#include "object.h"

Object::Object()
{ 
  m_parent = NULL;

  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  */

  Vertices = {
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
  };

  Indices = {
    2, 3, 4,
    8, 7, 6,
    1, 5, 6,
    2, 6, 7,
    7, 8, 4,
    1, 4, 8,
    1, 2, 4,
    5, 8, 6,
    2, 1, 6,
    3, 2, 7,
    3, 7, 4,
    5, 1, 8
  };

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);

  angleTranslate = 0.0f;
  angleRotate = 0.0f;

  m_paused = 0; //not paused
  m_spinDirection = 0; //spinning counter-clockwise
  m_orbitDirection = 0; //orbiting counter-clockwise
}

Object::Object(string filename)
{
  LoadObject(filename, &Vertices, &Indices);

  //uncomment below to print all vertices
  /*
  cout << "Vertices:" << endl;
  cout << "{" << endl;
  for (int i = 0; i < Vertices.size(); i++)
  {
    cout << "{{"
         << Vertices[i].vertex.x
         << ", "
         << Vertices[i].vertex.y
         << ", "
         << Vertices[i].vertex.z
         << "}{"
         << Vertices[i].color.x
         << ", "
         << Vertices[i].color.y
         << ", "
         << Vertices[i].color.z
         << "}}" << endl;
  }
  cout << "}" << endl;
  //*/

  //uncomment below to print all indices
  /*
  cout << "Indices:" << endl;
  cout << "{" << endl;
  for (int i = 0; i < Indices.size(); i++)
  {
    cout << Indices[i] << " ";
    if (((i + 1) % 3) == 0) cout << endl;
  }
  cout << "}" << endl;
  //*/

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);

  angleTranslate = 0.0f;
  angleRotate = 0.0f;

  m_paused = 0; //not paused
  m_spinDirection = 0; //spinning counter-clockwise
  m_orbitDirection = 0; //orbiting counter-clockwise
}

Object::~Object()
{
  m_children.clear();

  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
  angleRotate += dt * (M_PI/5000);
  model = glm::rotate(glm::mat4(1.0), angleRotate, glm::vec3(0.0,1.0,0.0));
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

bool Object::LoadObject(string in_filename, vector<Vertex>* out_vertices, vector<unsigned int>* out_indices)
{
  //file IO
  ifstream fin;
  string fileData;

  //material data
  vector<Material> materials;
  int currentMaterialIndex = 0;
  bool usingMtl = false;

  fin.open(in_filename);
  if (!fin.is_open())
  {
    cout << "Could not open object file" << endl;
    return false;
  }

  srand(time(NULL));

  out_vertices->clear();
  out_indices->clear();

  while (fin >> fileData)
  {
    if (fileData == "mtllib")
    {
      //load the material file

      string mtlFileName, mtlFilePath;

      fin >> mtlFileName;
      cout << "using material file: " << mtlFileName << endl;
      mtlFilePath = "..//objects//MTLS//" + mtlFileName;

      usingMtl = LoadMaterial(mtlFilePath, &materials);

      //uncomment below to print the material info
      /*
      for (int i = 0; i < materials.size(); i++)
      {
        cout << "Material " << i << ": " << materials[i].name << endl;
        cout << "Color: {"
             << materials[i].color.x << ", "
             << materials[i].color.y << ", "
             << materials[i].color.z << "}" << endl;
      }
      //*/
    }
    else if (fileData == "v")
    {
      //add the vertex

      Vertex newVertexObject(glm::vec3(1.0),glm::vec3(1.0));
      glm::vec3 newVertex;
      glm::vec3 newColor;
      float value;

      //get the x, y, z coordinates of the vertex
      fin >> value;
      newVertex.x = value;
      fin >> value;
      newVertex.y = value;
      fin >> value;
      newVertex.z = value;

      //generate the default material
      //(currently a medium-dark grayscale value)
      float grayscale = ( (float) (rand() % 20 + 50) ) / 100;
      newColor.x = grayscale;
      newColor.y = grayscale;
      newColor.z = grayscale;
      
      //assign the vertices
      newVertexObject.vertex.x = newVertex.x;
      newVertexObject.vertex.y = newVertex.y;
      newVertexObject.vertex.z = newVertex.z;

      //assign the materials
      newVertexObject.color.x = newColor.x;
      newVertexObject.color.y = newColor.y;
      newVertexObject.color.z = newColor.z;

      out_vertices->push_back(newVertexObject);
    }
    else if (fileData == "usemtl")
    {
      //switch the current material being applied

      string materialName;

      //search for name in material list
      fin >> materialName;
      for (int i = 0; i < materials.size(); i++)
      {
        if (materials[i].name == materialName)
        {
          //set the current material index to the index where the match occurred
          currentMaterialIndex = i;
          break;
        }
      }
    }
    else if (fileData == "f")
    {
      //add the index

      for (int i = 0; i < 3; i++)
      {
        unsigned int newIndex;
        int fileDataIterator = 0;
        string vertexIndex;

        //loop until '/' is hit or fileData size is reached
        //(only caring about the first index in the potential set of 3)
        fin >> fileData;
        while (fileData[fileDataIterator] != '/' && fileDataIterator < fileData.size())
        {
          vertexIndex.push_back(fileData[fileDataIterator]);
          fileDataIterator++;
        }

        //convert the index from string to int
        newIndex = (unsigned int) (stoi(vertexIndex) - 1);

        //if material file was opened successfully, use the data
        if (usingMtl)
        {
          //assign material to vertex located at the index
          out_vertices->at(newIndex).color.x = materials[currentMaterialIndex].color.x;
          out_vertices->at(newIndex).color.y = materials[currentMaterialIndex].color.y;
          out_vertices->at(newIndex).color.z = materials[currentMaterialIndex].color.z;
        }

        out_indices->push_back(newIndex);
      }
    }
  }

  fin.close();

  return true;
}

bool Object::LoadMaterial(string in_filename, vector<Material>* out_materials)
{
  ifstream fin;
  string fileData;

  fin.open(in_filename);
  if (!fin.is_open())
  {
    cout << "Could not open material file. Using default color option..." << endl;
    return false;
  }

  out_materials->clear();

  while (fin >> fileData)
  {
    if (fileData == "newmtl")
    {
      Material newMaterial;

      fin >> newMaterial.name;

      //loop until diffuse is found
      while (fileData != "Kd")
      {
        if (!(fin >> fileData)) //return false if diffuse is not found
        {
          fin.close();
          return false;
        }
      }

      fin >> newMaterial.color.x;
      fin >> newMaterial.color.y;
      fin >> newMaterial.color.z;

      out_materials->push_back(newMaterial);
    }
  }

  fin.close();
  return true;
}

glm::mat4 Object::GetModel()
{
  return model;
}

/*
glm::mat4* Object::GetModelReference()
{
  return &model;
}
*/

glm::mat4 Object::GetTranslation()
{
  return translation;
}

glm::mat4 Object::GetRotation()
{
  return rotation;
}

glm::mat4 Object::GetScale()
{
  return scale;
}

bool Object::IsPaused()
{
  return m_paused;
}

unsigned int Object::GetSpinDirection()
{
  return m_spinDirection;
}

unsigned int Object::GetOrbitDirection()
{
  return m_orbitDirection;
}

/*
void SetParent(glm::mat4* parent)
{
  m_parent = parent;
}
*/

void Object::SetParent(Object* parent)
{
  m_parent = parent;
}

void Object::AddChild(Object* child)
{
  m_children.push_back(child);
}

void Object::RemoveChild()
{
  if (!m_children.empty())
  {
    m_children.pop_back();
  }
}

void Object::SetPaused(bool paused)
{
  m_paused = paused;
}

void Object::SetSpinDirection(unsigned int spinDirection)
{
  m_spinDirection = spinDirection;
}

void Object::SetOrbitDirection(unsigned int orbitDirection)
{
  m_orbitDirection = orbitDirection;
}
