#version 430

layout (location=0) in vec3 position;

// uniform mat4 m_matrix;
// uniform mat4 v_matrix;
uniform mat4 proj_matrix;
uniform mat4 mv_matrix;
uniform float time_factor;

out vec4 varyingColor;

mat4 buildTranslate(float x, float y, float z);
mat4 buildScale(float x, float y, float z);
mat4 buildRotateX(float rad);
mat4 buildRotateY(float rad);
mat4 buildRotateZ(float rad);

void main(void) { 
	// float i = gl_InstanceID + time_factor;
	// float a = sin(0.12*i + 0.5)*5.0;
	// float b = sin(0.30*i - 0.5)*5.0;
	// float c = sin(0.23*i)*5.0;

	// mat4 localRotX = buildRotateX(0.43 * i);
	// mat4 localRotY = buildRotateY(0.21 * i);
	// mat4 localRotZ = buildRotateZ(0.31 * i);
	// mat4 localTrans = buildTranslate(a,b,c);
	
	// mat4 newModelMatrix = m_matrix * localRotX * localRotY * localRotZ * localTrans;
	// mat4 mv_matrix = v_matrix * newModelMatrix;

	gl_Position = proj_matrix * mv_matrix * vec4(position, 1.0);
	varyingColor = vec4(position,1.0) * 0.5 + vec4(0.5,0.5,0.5,0.5);
}

mat4 buildTranslate(float x, float y, float z)
{
	mat4 trans = mat4(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, x, y, z, 1.0 );
	return trans;
}

// builds and returns a matrix that performs a rotation around the X axis
mat4 buildRotateX(float rad)
{
	mat4 xrot = mat4(1.0, 0.0, 0.0, 0.0, 0.0, cos(rad), -sin(rad), 0.0, 0.0, sin(rad), cos(rad), 0.0, 0.0, 0.0, 0.0, 1.0 );
	return xrot;
}

// builds and returns a matrix that performs a rotation around the Y axis
mat4 buildRotateY(float rad)
{
	mat4 yrot = mat4(cos(rad), 0.0, sin(rad), 0.0, 0.0, 1.0, 0.0, 0.0, -sin(rad), 0.0, cos(rad), 0.0, 0.0, 0.0, 0.0, 1.0 );
	return yrot;
}

// builds and returns a matrix that performs a rotation around the Z axis
mat4 buildRotateZ(float rad)
{
	mat4 zrot = mat4(cos(rad), -sin(rad), 0.0, 0.0, sin(rad), cos(rad), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
	return zrot;
}

// builds and returns a scale matrix
mat4 buildScale(float x, float y, float z)
{
	mat4 scale = mat4(x, 0.0, 0.0, 0.0, 0.0, y, 0.0, 0.0, 0.0, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0 );
	return scale;
}
