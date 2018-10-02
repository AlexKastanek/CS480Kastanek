#include "model.h"

void Model::Render()
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    for ( int i = 0; i<VBs.size();i++) {

        glBindBuffer(GL_ARRAY_BUFFER, VBs[i]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, color));

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBs[i]);



        glDrawElements(GL_TRIANGLES, numIndices[i], GL_UNSIGNED_INT, 0);

    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}


Model* Model::LoadObject(string in_filename) {
    std::vector<Vertex> out_vertices;
    std::vector<unsigned int> out_indices;
    Model* model = new Model;
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(in_filename.c_str(),
                                             aiProcess_Triangulate);//read in vertices, with triangulation
    cout << scene->mNumMeshes << " meshes found" << endl;
    cout << scene->mNumMaterials << " materials found" << endl;


    aiMesh *mesh = scene->mMeshes[0];

    out_vertices.clear();
    out_indices.clear();

    for (int i = 0; i < scene->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[i];
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        aiString materialName;
        material->Get(AI_MATKEY_NAME, materialName);
        cout << "using material " << mesh->mMaterialIndex << ": " << materialName.C_Str() << endl;
        //cout << "using material " << i << endl;

        for (int j = 0; j < mesh->mNumVertices; j++) {
            aiVector3D aiVec = mesh->mVertices[j];
            glm::vec3 vertex = glm::vec3(aiVec.x, aiVec.y, aiVec.z);

            aiColor4D aiColor;
            glm::vec3 color;
            if (AI_SUCCESS == material->Get(AI_MATKEY_COLOR_DIFFUSE, aiColor)
                && scene->mNumMaterials > 1) {
                cout << "Color obtained: {" << aiColor.r << "," << aiColor.g << "," << aiColor.b << "}" << endl;
                color = glm::vec3(aiColor.r, aiColor.g, aiColor.b);
            } else {
                //default setting is random colors
                float default_color = (float) (((float) (rand() % 100 + 1)) / 100);
                color = glm::vec3(default_color, default_color, default_color);
            }

            Vertex *temp = new Vertex(vertex, color); //create the Vertex type to be pushed
            out_vertices.push_back(*temp);
            delete temp;
        }

        //cout << "Number of faces: " << mesh->mNumFaces << endl;
        for (int j = 0; j < mesh->mNumFaces; j++) {
            aiFace face = mesh->mFaces[j];

            //push each vertex to create the index
            out_indices.push_back(face.mIndices[0]);
            out_indices.push_back(face.mIndices[1]);
            out_indices.push_back(face.mIndices[2]);
        }
        /*for(unsigned int i = 0; i < Indices.size(); i++)
        {
            Indices[i] = Indices[i] - 1;
        }*/
        GLuint VB;
        GLuint IB;
        glGenBuffers(1, &VB);
        glBindBuffer(GL_ARRAY_BUFFER, VB);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * out_vertices.size(), &out_vertices[0], GL_STATIC_DRAW);
        glGenBuffers(1, &IB);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * out_indices.size(), &out_indices[0], GL_STATIC_DRAW);
        model->IBs.push_back(IB);
        model->VBs.push_back(VB);
        model->numIndices.push_back(out_indices.size());
        out_indices.clear();
        out_vertices.clear();
      //  for(const GLuint& VB:VBs){
       //     VBs.push_back(VB);
       // }


       /* for(const GLuint& IB:IBs) {
            IBs.push_back(IB);
        }*/
    }
    return model;
}
//
// Created by mari on 10/2/18.
//

