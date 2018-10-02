//
// Created by mari on 10/2/18.
//
#include <vector>
#include "graphics_headers.h"
#include <string>

using namespace std;
#ifndef TUTORIAL_MODEL_H
#define TUTORIAL_MODEL_H
class Model {
public:
    //Model();
    //~Model();

    static Model* LoadObject(string in_filename);
    void Render();
private:
    vector<GLuint> VBs;
    vector<GLuint> IBs;
    vector<unsigned> numIndices;
 //   static bool LoadObject(string in_filename, vector <Vertex> *out_vertices, vector<unsigned int> *out_indices);

};
#endif //TUTORIAL_MODEL_H
