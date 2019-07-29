#version 330 core

in vec2 outputTextCoord;
uniform sampler2D diffuse;


void main()
{
   gl_FragColor = texture2D(diffuse, outputTextCoord);
   //gl_FragColor = vec4(1.0, 0.5, 0.2, 1.0); 
}