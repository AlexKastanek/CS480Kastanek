#include "shadow.h"

Shadow::Shadow()
{

}

Shadow::~Shadow()
{

}

void Shadow::Initialize()
{
  // Generate depth map FBO
  glGenFramebuffers(1, &m_depthMapFBO);

  // Create depth map texture
  glGenTextures(1, &m_depthMap);
  glBindTexture(GL_TEXTURE_2D, m_depthMap);
  glTexImage2D(
    GL_TEXTURE_2D, 
    0, 
    GL_DEPTH_COMPONENT, 
    m_shadowWidth, 
    m_shadowHeight,
    0,
    GL_DEPTH_COMPONENT,
    GL_FLOAT,
    NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Attach depth map texture as FBO's depth buffer
  glBindFramebuffer(GL_FRAMEBUFFER, m_depthMapFBO);
  glFramebufferTexture2D(
    GL_FRAMEBUFFER,
    GL_DEPTH_ATTACHMENT,
    GL_TEXTURE_2D,
    m_depthMap,
    0);
  glDrawBuffer(GL_NONE);
  glReadBuffer(GL_NONE);

  // Reset to default frame buffer
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Shadow::Update()
{

}

void Shadow::Bind(Shader& shader)
{
  glm::mat4 lightMatrix = m_lightProjection * m_lightView;
  GLint lightMatrixLocation = shader.GetUniformLocation("lightMatrix");
  glUniformMatrix4fv(
    lightMatrixLocation, 
    1, 
    GL_FALSE, 
    glm::value_ptr(lightMatrix));

  glViewport(0, 0, m_shadowWidth, m_shadowHeight);
  glBindFramebuffer(GL_FRAMEBUFFER, m_depthMapFBO);
  glClear(GL_DEPTH_BUFFER_BIT);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_depthMap); 
}

void Shadow::Reset()
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Shadow::SetLightProjection(glm::mat4 lightProjection)
{
  m_lightProjection = lightProjection;
}

void Shadow::SetLightView(glm::mat4 lightView)
{
  m_lightView = lightView;
}