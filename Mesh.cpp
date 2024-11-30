#include "Mesh.h"

Mesh::Mesh() {
	vertices = {};
	indices = {};
}
void Mesh::load(string filename) {
	// îòîáðàæåíèå âåðøèíû (ïî èñïîëüçóåìûì åþ àòðèáóòàì) íà èíäåêñ â ìàññèâå âåðøèí
	map<string, int> vertexToIndexTable;
	ifstream file(filename);
	// âåêòîð äëÿ õðàíåíèÿ ãåîìåòðè÷åñêèõ êîîðäèíàò
	vector<vec3> v;
	// âåêòîð äëÿ õðàíåíèÿ íîðìàëåé
	vector<vec3> n;
	// âåêòîð äëÿ õðàíåíèÿ òåêñòóðíûõ êîîðäèíàò
	vector<vec3> t;
	// âåêòîð äëÿ õðàíåíèÿ èíäåêñîâ àòðèáóòîâ, äëÿ ïîñòðîåíèÿ âåðøèí
	vector<ivec3> fPoints;
	int index = 0;
	while (!file.eof()) {
		string param;
		file >> param;
		if (param == "v") {
			float x, y, z;
			file >> x >> y >> z;
			v.push_back(vec3(x, y, z));
		}
		else if (param == "vt") {
			float x, y, z;
			file >> x >> y >> z;
			t.push_back(vec3(x, y, z));
		}
		else if (param == "vn") {
			float x, y, z;
			file >> x >> y >> z;
			n.push_back(vec3(x, y, z));
		}
		else if (param == "f") {
			string str;
			for (int i = 0; i < 3; i++)
			{
				ivec3 face;
				file >> str;
				map<string, int>::iterator iter = vertexToIndexTable.find(str);
				if (iter != vertexToIndexTable.end())
				{
					indices.push_back(iter->second);
					continue;
				}
				stringstream ss(str);
				string temp;
				getline(ss, temp, '/');
				face[0] = stoi(temp);
				getline(ss, temp, '/');
				face[1] = stoi(temp);
				getline(ss, temp, '/');
				face[2] = stoi(temp);
				vertexToIndexTable.insert(make_pair(str, index));
				indices.push_back(index++);
				fPoints.push_back(face);
			}
		}

	}
	for (glm::ivec3& index : fPoints)
	{
		Vertex vert;
		vert.coord = v[index.x - 1];
		vert.texCoord = t[index.y - 1];
		vert.normal = n[index.z - 1];

		vertices.push_back(vert);
	}
}

void Mesh::draw()
{
	if (vertices.size() == 0) return;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), value_ptr(vertices[0].coord));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), value_ptr(vertices[0].normal));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), value_ptr(vertices[0].texCoord));
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

};
