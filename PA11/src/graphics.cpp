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

   // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }

  cout << "CHECK GRAPHICS FINISHED CAMERA ALLOC" << endl;

  //Init the world
  m_world = new World(glm::vec3(0.0f, -0.00005f, 0.0f));
  if (!m_world->Initialize())
  {
    printf("World Failed to Initialize\n");
    return false;
  }

  cout << "CHECK GRAPHICS FINISHED PHYSICS AND WORLD ALLOC" << endl;

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
  m_currentShader = m_fragmentBasedShader;

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

  Light mainPointLight;

  mainPointLight.position = glm::vec4(-50.0f, 20.0f, 90.0f, 1.0f);
  mainPointLight.ambient = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);
  mainPointLight.diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  mainPointLight.specular = glm::vec4(3.0f, 3.0f, 3.0f, 3.0f);
  mainPointLight.direction = glm::vec3(0.0f, -1.0f, 0.0f);
  mainPointLight.angle = 180.0f;
  mainPointLight.shininess = 50;
  mainPointLight.attenuation = 0.000001f;

  m_lights.push_back(mainPointLight);

  ambientMod = new float[m_numLights];
  diffuseMod = new float[m_numLights];
  specularMod = new float[m_numLights];

  for (int i = 0; i < m_numLights; i++)
  {
    ambientMod[i] = 0;
    diffuseMod[i] = 0;
    specularMod[i] = 0;
  }

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
  // Update the camera
  m_camera->Update(dt);

  // Update the world
  m_world->m_cameraTransform = m_camera->GetModel();
  m_world->Update(dt);
}

void Graphics::Render()
{

  // Clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_currentShader->Enable();

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  //Send in the number of lights
  glUniform1i(m_currentShader->GetUniformLocation("numLights"), m_numLights);

  //Send the data for each light
  for (int i = 0; i < m_numLights; i++)
  {
    passLightToShader(i);
  }

  //Send in the texture sampler
  glUniform1i(m_currentShader->GetUniformLocation("gSampler"), 0);

  /* render the objects */

  //render generic objects
  m_world->Render();

  //render specific objects
  for (int i = 0; i < m_world->GetObjectCount(); i++)
  {
    m_world->Render(m_modelMatrix, i);
  }

  //cout << "finished rendering objects" << endl;

  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

void Graphics::passLightToShader(int lightIndex)
{
  string lightArray = "lights[" + to_string(lightIndex) + "]";
  string variableName;

  //pass the light position
  variableName = lightArray + ".lightPosition";
  glUniform4f(m_currentShader->GetUniformLocation(variableName.c_str()), 
    m_lights[lightIndex].position.x, 
    m_lights[lightIndex].position.y, 
    m_lights[lightIndex].position.z, 
    1.0);

  //pass the lighting components
  variableName = lightArray + ".ambientProduct";
  glUniform4f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].ambient.x + ambientMod[lightIndex], 
    m_lights[lightIndex].ambient.y + ambientMod[lightIndex], 
    m_lights[lightIndex].ambient.z + ambientMod[lightIndex], 
    m_lights[lightIndex].ambient.w);
  variableName = lightArray + ".diffuseProduct";
  glUniform4f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].diffuse.x + diffuseMod[lightIndex], 
    m_lights[lightIndex].diffuse.y + diffuseMod[lightIndex], 
    m_lights[lightIndex].diffuse.z + diffuseMod[lightIndex], 
    m_lights[lightIndex].diffuse.w);
  variableName = lightArray + ".specularProduct";
  glUniform4f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].specular.x, 
    m_lights[lightIndex].specular.y, 
    m_lights[lightIndex].specular.z, 
    m_lights[lightIndex].specular.w);

  //pass additional lighting data
  variableName = lightArray + ".lightDirection";
  glUniform3f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].direction.x, 
    m_lights[lightIndex].direction.y, 
    m_lights[lightIndex].direction.z);
  variableName = lightArray + ".lightAngle";
  glUniform1f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].angle);
  variableName = lightArray + ".shininess";
  glUniform1f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].shininess);
  variableName = lightArray + ".attenuationProduct";
  glUniform1f(m_currentShader->GetUniformLocation(variableName.c_str()),
    m_lights[lightIndex].attenuation);
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

void Graphics::shooooooooooot()
{
    glm::vec3 pos = m_camera->GetPosition();
    
    cout << "POSITION: " << pos.x << " " << pos.y << " "  << pos.z << endl;
    
    m_world->createBullet(pos.x, pos.y, pos.z, m_camera->GetPitch(), m_camera->GetYaw());
}