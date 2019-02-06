#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
//uniform vec3 OtherColor=vec3(-1,-1,-1);
uniform bool flagColor;
out vec4 Fragment;

void main()
{
	Fragment = vec4(Color,1);
	
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
	{
		if(flagColor==true)
		{
			//OtherColor=vec3(1-SolidColor.r,1-SolidColor.g,1-SolidColor.b);
			//OtherColor=vec3(SolidColor.r,SolidColor.g,SolidColor.b);
			Fragment=vec4(vec3(1-SolidColor.r,1-SolidColor.g,1-SolidColor.b),1);
		}
		else
			Fragment = vec4(SolidColor, 1);
	}
	else if((flagColor==true)&&(SolidColor.r == -1.0 && SolidColor.g == -1.0 && SolidColor.b == -1.0))
			Fragment=vec4(vec3(1-Color.r,1-Color.g,1-Color.b),1);
	return;
}