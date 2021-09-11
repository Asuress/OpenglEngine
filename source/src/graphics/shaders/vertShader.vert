#version 430

layout (location=0) in vec3 aPos;

// uniform mat4 mv_matrix;
// uniform mat4 proj_matrix;

void main(void)
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}