#include "graphics.h"

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

  // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }

  /*// Create the objects
  m_object = new Object("..//assets//" + m_objectFilename);
  m_planet = new Planet(5.0, 5.0);
  m_moon = new Moon(30.0, 30.0);

  // Build the object hierarchy
  m_planet->AddChild(m_moon);
  m_moon->SetParent(m_planet);*/

  // Set up the shaders
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_shader->AddShader(GL_VERTEX_SHADER))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_shader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  return true;
}

void Graphics::Update(unsigned int dt)
{
  //cout << "CHECK GRAPHICS UPDATE" << endl;

  // Update the objects
  /*m_object->Update(dt);
  m_planet->Update(dt);
  m_moon->Update(dt);*/
  m_camera->Update(dt);
}

void Graphics::Render()
{
  //cout << "CHECK GRAPHICS RENDER" << endl;

  //clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_shader->Enable();

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  // Render the objects

  //Object specified at command line
  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_object->GetModel()));
  m_object->Render();

  //Planet
  //glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_planet->GetModel()));
  //m_planet->Render();

  //Moon
  //glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_moon->GetModel()));
  //m_moon->Render();

  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

bool Graphics::IsPlanetPaused()
{
  return m_planet->IsPaused();
}

unsigned int Graphics::GetPlanetSpin()
{
  return m_planet->GetSpinDirection();
}

unsigned int Graphics::GetPlanetOrbit()
{
  return m_planet->GetOrbitDirection();
}

void Graphics::SetPlanetPaused(bool paused)
{
  m_planet->SetPaused(paused);
}

void Graphics::SetPlanetSpin(unsigned int spin)
{
  m_planet->SetSpinDirection(spin);
}

void Graphics::SetPlanetOrbit(unsigned int orbit)
{
  m_planet->SetOrbitDirection(orbit);
}

void Graphics::SetCameraVelocity(glm::vec3 velocity)
{
  m_camera->SetVelocity(velocity);
}

void Graphics::SetCameraVelocity(float x, float y, float z)
{
  m_camera->SetVelocity(x, y, z);
}

void Graphics::SetCameraVelocity(char axis, float value)
{
  switch (axis)
  {
    case 'x':
      m_camera->SetVelocityX(value);
      break;
    case 'y':
      m_camera->SetVelocityY(value);
      break;
    case 'z':
      m_camera->SetVelocityZ(value);
      break;
    case 'X':
      m_camera->SetVelocityX(value);
      break;
    case 'Y':
      m_camera->SetVelocityY(value);
      break;
    case 'Z':
      m_camera->SetVelocityZ(value);
      break;
    default:
      cout << "ERROR: Invalid camera velocity axis" << endl;
  }
}

void Graphics::SetObjectFilename(string objectFilename)
{
  m_objectFilename = objectFilename;
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

 void CreatePlanets(string configFile)
 {
    //Source Code   
    /*// Create the objects
    m_object = new Object("..//assets//" + m_objectFilename);
    m_planet = new Planet(5.0, 5.0);
    m_moon = new Moon(30.0, 30.0);

    // Build the object hierarchy
    m_planet->AddChild(m_moon);
    m_moon->SetParent(m_planet);*/
    
    std::ifstream fin;
    fin.open(configFile.c_str());//open file
    
    char* format;
    gbg = new char;
    getline(fin, format);
    
    for(int i=0 ; i<9 ; i++)
    {
    }
 
 }
 
 void UpdatePlanets(unsigned int dt)
 {
 }
 
 void RenderPlanets()
 {
 }

