#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"

using namespace std;

enum CameraMode {
    Mode_Free = 0,
    Mode_Focus = 1
};

class Camera
{
  public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    void Update(unsigned int dt);

    glm::mat4 GetProjection();
    glm::mat4 GetView();
    glm::vec3 GetPosition();
    glm::vec3 GetVelocity();
    float GetMoveSpeed();
    unsigned int GetMode();

    //get individual x,y,z values
    float GetPositionX();
    float GetPositionY();
    float GetPositionZ();
    float GetVelocityX();
    float GetVelocityY();
    float GetVelocityZ();

    void SetPosition(glm::vec3 position);
    void SetPosition(float x, float y, float z);
    void SetVelocity(glm::vec3 velocity);
    void SetVelocity(float x, float y, float z);
    void SetMoveSpeed(float moveSpeed);
    void SetMode(unsigned int mode);

    //set individual x,y,z values
    void SetPositionX(float x);
    void SetPositionY(float y);
    void SetPositionZ(float z);
    void SetVelocityX(float x);
    void SetVelocityY(float y);
    void SetVelocityZ(float z);
  
  private:
    glm::mat4 projection;
    glm::mat4 view;

    glm::vec3 m_position;
    glm::vec3 m_velocity;

    float m_moveSpeed;

    unsigned int m_mode;
};

#endif /* CAMERA_H */
