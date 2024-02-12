#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <string_view>

Texture::Texture() {
	m_width = 0;
	m_heigth = 0;
	m_channels = 0;
	m_texture = 0;
}

void Texture::Cleanup() {
	glDeleteTextures(1, &m_texture);
}

bool Texture::EndsWith(const std::string& _str, const std::string& _suffix)
{
	if (_str.length() < _suffix.length()) {
		return false;
	}
	return _str.compare(_str.length() - _suffix.length(), _suffix.length(), _suffix) == 0;

}



void Texture::LoadTexture(string _filename) {
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	GLubyte* data = stbi_load(_filename.c_str(), &m_width, &m_heigth, &m_channels, 0);
	M_ASSERT(data != nullptr, "Failed to load texture!");
	if (EndsWith(_filename, ".png")) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	}
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

void Texture::LoadCubemap(vector<std::string> _faces) {
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_texture);

	for (unsigned int i = 0; i < _faces.size(); i++) {
		stbi_set_flip_vertically_on_load(false);
		GLubyte* data = stbi_load(_faces[i].c_str(), &m_width, &m_heigth, &m_channels, 0);
		M_ASSERT(data != nullptr, "Failed to load cubemap texture");
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0, GL_RGB, m_width, m_heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

