#version 400

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coords;
layout(location = 2) in vec3 normal;

out vec3 colour;
out vec2 pass_texture_coords;
out vec3 surface_normal;;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main(void){

	pass_texture_coords = texture_coords;
	colour = vec3(position.x+0.5,0.0,position.y+0.5);
	gl_Position = projection * view * transform * vec4(position, 1.0);
	//gl_Position = projection * transform * vec4(position, 1.0);
	//gl_Position = vec4(position, 1.0);

	surface_normal = normal;
}