mat4 buildTranslate(float x, float y, float z)
{ 
	mat4 trans = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, 1.0, 0.0, 0.0, 
					0.0, 0.0, 1.0, 0.0,
					x,	 y,   z,   1.0 );
	return trans;
}