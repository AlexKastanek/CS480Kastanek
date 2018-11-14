#include "graphics.h"
#include <stdlib.h>

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool Graphics::Initialize(int width, int height)
{
  //cout << "CHECK GRAPHICS INIT" << endl;

  // Used for the linux OS
  #if !defined(__APPLE__) && !defined(MACOSX)
    // cout << glewGetString(GLEW_VERSION) << endl;
    glewExperimental = GL_TRUE;

    auto status = glewInit();

    // This is here to grab the error that comes from glew init.
    // This error is an GL_INVALID_ENUM that has no effects on the performance
    glGetError();

    //Check for error
    if (status != GLEW_OK)
    {
      std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
      return false;
    }
  #endif

  // For OpenGL 3
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  //Init Physics
  //m_physics = new Physics();

  //Init the world
  m_world = new World(glm::vec3(0.0f, -0.0005f, -0.0001f));
  if (!m_world->Initialize())
  {
    printf("World Failed to Initialize\n");
    return false;
  }

  cout << "CHECK GRAPHICS FINISHED PHYSICS AND WORLD ALLOC" << endl;

  // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }

  cout << "CHECK GRAPHICS FINISHED CAMERA ALLOC" << endl;

  // Init the objects
  //m_board = new Board("..//assets//Board.obj", 13.0f);

  //cout << "CHECK GRAPHICS FINISHED BOARD ALLOC" << endl;

  // Set up the shaders
  /*
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }
  */
  m_vertexBasedShader = new Shader();
  if (!m_vertexBasedShader->Initialize())
  {
    printf("Vertex based shader failed to initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_vertexBasedShader->AddShader(GL_VERTEX_SHADER, 0))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_vertexBasedShader->AddShader(GL_FRAGMENT_SHADER, 0))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_vertexBasedShader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  // Set up the shaders
  /*
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }
  */
  m_fragmentBasedShader = new Shader();
  if (!m_fragmentBasedShader->Initialize())
  {
    printf("Vertex based shader failed to initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_fragmentBasedShader->AddShader(GL_VERTEX_SHADER, 1))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_fragmentBasedShader->AddShader(GL_FRAGMENT_SHADER, 1))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_fragmentBasedShader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  //set which lighting type is currently being used (default is vertex-based)
  m_currentShader = m_vertexBasedShader;
  m_currentShaderID = 0;

  /* set the light data */

  /*
  gLight.position = glm::vec4(0.0f, 20.0f, 0.0f, 1.0f);
  gLight.ambient = glm::vec4(0.25f, 0.25f, 0.25f, 1.0f);
  gLight.diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  gLight.specular = glm::vec4(2.0f, 2.0f, 2.0f, 1.0f);
  gLight.direction = glm::vec3(0.0f, -1.0f, 0.0f);
  gLight.angle = 40.0f;
  gLight.shininess = 50;
  gLight.attenuation = 0.001f;
  */

  m_spotLight.position = glm::vec4(0.0f, 20.0f, 0.0f, 1.0f);
  m_spotLight.ambient = glm::vec4(0.25f, 0.25f, 0.25f, 1.0f);
  m_spotLight.diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  m_spotLight.specular = glm::vec4(2.0f, 2.0f, 2.0f, 1.0f);
  m_spotLight.direction = glm::vec3(0.0f, -1.0f, 0.0f);
  m_spotLight.angle = 40.0f;
  m_spotLight.shininess = 50;
  m_spotLight.attenuation = 0.001f;

  m_pointLight.position = glm::vec4(0.0f, 2.0f, 80.0f, 1.0f);
  m_pointLight.ambient = glm::vec4(0.25f, 0.25f, 0.25f, 1.0f);
  m_pointLight.diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  m_pointLight.specular = glm::vec4(2.0f, 2.0f, 2.0f, 1.0f);
  m_pointLight.direction = glm::vec3(0.0f, -1.0f, 0.0f);
  m_pointLight.angle = 180.0f;
  m_pointLight.shininess = 50;
  m_pointLight.attenuation = 0.00001f;

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_currentShader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_currentShader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_currentShader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  //glEnable(GL_LIGHTING);

  //enable transparency
  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  cout << "CHECK GRAPHICS FINISHED INITIALIZE" << endl;

  return true;
}

void Graphics::Update(unsigned int dt)
{
  //cout << "CHECK GRAPHICS UPDATE" << endl;

  // Update the physics world
  //m_physics->Update(dt);

  // Update the objects
  //m_board->Update(dt);

  // Update the world
  m_world->Update(dt);

  // Update the lights
  glm::vec3 ballPos = m_world->GetBall().GetPosition();
  m_spotLight.position.x = ballPos.x;
  m_spotLight.position.z = ballPos.z;

  // Update the camera
  m_camera->Update(dt);
}

void Graphics::Render()
{
  //cout << "CHECK GRAPHICS RENDER" << endl;
//   cout << "("
//        << gLight.position.x << ", "
//        << gLight.position.y << ", "
//        << gLight.position.z << ")"
//        << endl;

  //clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_currentShader->Enable();

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  glUniform1i(m_currentShader->GetUniformLocation("numLights"), 2);

  //spotlight
  glUniform4f(m_currentShader->GetUniformLocation("lights[0].lightPosition"), 
    m_spotLight.position.x, m_spotLight.position.y, m_spotLight.position.z, 1.0);

  glUniform4f(m_currentShader->GetUniformLocation("lights[0].ambientProduct"),
    m_spotLight.ambient.x + ambientMod, m_spotLight.ambient.y + ambientMod, 
    m_spotLight.ambient.z + ambientMod, m_spotLight.ambient.w);
  glUniform4f(m_currentShader->GetUniformLocation("lights[0].diffuseProduct"),
    m_spotLight.diffuse.x + diffuseMod, m_spotLight.diffuse.y + diffuseMod, 
    m_spotLight.diffuse.z + diffuseMod, m_spotLight.diffuse.w);
  glUniform4f(m_currentShader->GetUniformLocation("lights[0].specularProduct"),
    m_spotLight.specular.x, m_spotLight.specular.y, 
    m_spotLight.specular.z, m_spotLight.specular.w);

  glUniform3f(m_currentShader->GetUniformLocation("lights[0].lightDirection"),
    m_spotLight.direction.x, m_spotLight.direction.y, m_spotLight.direction.z);
  glUniform1f(m_currentShader->GetUniformLocation("lights[0].lightAngle"),
    m_spotLight.angle);
  glUniform1f(m_currentShader->GetUniformLocation("lights[0].shininess"),
    m_spotLight.shininess);
  glUniform1f(m_currentShader->GetUniformLocation("lights[0].attenuationProduct"),
    m_spotLight.attenuation);

  //pointlight
  glUniform4f(m_currentShader->GetUniformLocation("lights[1].lightPosition"), 
    m_pointLight.position.x, m_pointLight.position.y, m_pointLight.position.z, 1.0);

  glUniform4f(m_currentShader->GetUniformLocation("lights[1].ambientProduct"),
    m_pointLight.ambient.x + ambientMod, m_pointLight.ambient.y + ambientMod, 
    m_pointLight.ambient.z + ambientMod, m_pointLight.ambient.w);
  glUniform4f(m_currentShader->GetUniformLocation("lights[1].diffuseProduct"),
    m_pointLight.diffuse.x + diffuseMod, m_pointLight.diffuse.y + diffuseMod, 
    m_pointLight.diffuse.z + diffuseMod, m_pointLight.diffuse.w);
  glUniform4f(m_currentShader->GetUniformLocation("lights[1].specularProduct"),
    m_pointLight.specular.x, m_pointLight.specular.y, 
    m_pointLight.specular.z, m_pointLight.specular.w);

  glUniform3f(m_currentShader->GetUniformLocation("lights[1].lightDirection"),
    m_pointLight.direction.x, m_pointLight.direction.y, m_pointLight.direction.z);
  glUniform1f(m_currentShader->GetUniformLocation("lights[1].lightAngle"),
    m_pointLight.angle);
  glUniform1f(m_currentShader->GetUniformLocation("lights[1].shininess"),
    m_pointLight.shininess);
  glUniform1f(m_currentShader->GetUniformLocation("lights[1].attenuationProduct"),
    m_pointLight.attenuation);

  glUniform1i(m_currentShader->GetUniformLocation("gSampler"), 0);

  //render board
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"), 
    gLight.specular.x + boardSpecularMod, 
    gLight.specular.y + boardSpecularMod, 
    gLight.specular.z + boardSpecularMod, 
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 't');

  //render ball
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"), 
    gLight.specular.x + ballSpecularMod, 
    gLight.specular.y + ballSpecularMod, 
    gLight.specular.z + ballSpecularMod, 
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 'b');

  m_world->Render(m_modelMatrix, 'd');

  //render flippers
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"), 
    gLight.specular.x + flipperSpecularMod, 
    gLight.specular.y + flipperSpecularMod, 
    gLight.specular.z + flipperSpecularMod, 
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 'f');

  //render plunger
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"),
    gLight.specular.x,
    gLight.specular.y,
    gLight.specular.z,
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 'p');
  
  //render cylinder
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"), 
    gLight.specular.x + cylinderSpecularMod, 
    gLight.specular.y + cylinderSpecularMod, 
    gLight.specular.z + cylinderSpecularMod, 
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 'c');

  //render launch barrier
  /*
  glUniform4f(
    m_currentShader->GetUniformLocation("specularProduct"),
    gLight.specular.x,
    gLight.specular.y,
    gLight.specular.z,
    gLight.specular.w);
  */

  m_world->Render(m_modelMatrix, 'l');

  //cout << "finished rendering objects" << endl;

  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

std::string Graphics::ErrorString(GLenum error)
{
  if(error == GL_INVALID_ENUM)
  {
    return "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument.";
  }

  else if(error == GL_INVALID_VALUE)
  {
    return "GL_INVALID_VALUE: A numeric argument is out of range.";
  }

  else if(error == GL_INVALID_OPERATION)
  {
    return "GL_INVALID_OPERATION: The specified operation is not allowed in the current state.";
  }

  else if(error == GL_INVALID_FRAMEBUFFER_OPERATION)
  {
    return "GL_INVALID_FRAMEBUFFER_OPERATION: The framebuffer object is not complete.";
  }

  else if(error == GL_OUT_OF_MEMORY)
  {
    return "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command.";
  }
  else
  {
    return "None";
  }
}

/*
void Graphics::moveLight(char input)
{
  switch (input)
  {
    case 'w':
      gLight.position.z += 1;
      break;
    case 'a':
      gLight.position.x += 1;
      break;
    case 's':
      gLight.position.z -= 1;
      break;
    case 'd':
      gLight.position.x -= 1;
      break;
    case '+':
      gLight.position.y += 1;
      break;
    case '-':
      gLight.position.y -= 1;
      break;
    case '^':
      gLight.direction.z += 0.1;
      break;
    case 'v':
      gLight.direction.z -= 0.1;
      break;
    case '<':
      gLight.direction.x += 0.1;
      break;
    case '>':
      gLight.direction.x -= 0.1;
      break;
    default: break;
  }
}
*/

void Graphics::changeShader()
{
  if (m_currentShaderID == 0)
  {
    cout << "Changing to fragment based lighting" << endl;
    m_currentShader = m_fragmentBasedShader;
    m_currentShaderID = 1;
  }
  else
  {
    cout << "Changing to vertex based lighting" << endl;
    m_currentShader = m_vertexBasedShader;
    m_currentShaderID = 0;
  }

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_currentShader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    //return;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_currentShader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    //return;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_currentShader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    //return;
  }
}

void Graphics::increaseBrightness()
{
    ambientMod += .05;
    cout << "Scene brightness set to " << ambientMod << endl;
}

void Graphics::decreaseBrightness()
{
    ambientMod -= .05;
    cout << "Scene brightness set to " << ambientMod << endl;
}

void Graphics::increaseDiffuse()
{
  diffuseMod += diffuseAdj;
  cout << "Spot light brightness set to " << diffuseMod << endl;
}

void Graphics::decreaseDiffuse()
{
  diffuseMod -= diffuseAdj;
  cout << "Spot light brightness set to " << diffuseMod << endl;
}

void Graphics::increaseSpecular(unsigned int object)
{
  switch (object)
  {
    case 0:
      boardSpecularMod += specularAdj;
      cout << "Board specular set to " << boardSpecularMod << endl;
      break;
    case 1:
      ballSpecularMod += specularAdj;
      cout << "Ball specular set to " << ballSpecularMod << endl;
      break;
    case 2:
      flipperSpecularMod += specularAdj;
      cout << "Flipper specular set to " << flipperSpecularMod << endl;
      break;
    case 3:
      cylinderSpecularMod += specularAdj;
      cout << "Cylinder specular set to " << cylinderSpecularMod << endl;
      break;
    default: break;
  }
}

void Graphics::decreaseSpecular(unsigned int object)
{
  switch (object)
  {
    case 0:
      boardSpecularMod -= specularAdj;
      cout << "Board specular set to " << boardSpecularMod << endl;
      break;
    case 1:
      ballSpecularMod -= specularAdj;
      cout << "Ball specular set to " << ballSpecularMod << endl;
      break;
    case 2:
      flipperSpecularMod -= specularAdj;
      cout << "Flipper specular set to " << flipperSpecularMod << endl;
      break;
    case 3:
      cylinderSpecularMod -= specularAdj;
      cout << "Cylinder specular set to " << cylinderSpecularMod << endl;
      break;
    default: break;
  }
}

void Graphics::increaseSpotLightRadius()
{
  if (m_spotLight.angle < 180.0f)
  {
    m_spotLight.angle += 1.0f;
  }
  cout << "Spot light angle set to " << m_spotLight.angle << " degrees" << endl;
}

void Graphics::decreaseSpotLightRadius()
{
  if (m_spotLight.angle > 0.0f)
  {
    m_spotLight.angle -= 1.0f;
  }
  cout << "Spot light angle set to " << m_spotLight.angle << " degrees" << endl;
}