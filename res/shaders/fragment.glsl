#version 400 core

in vec3 colour;
in vec2 pass_texture_coords;
in vec3 surface_normal;

out vec4 out_Color;

uniform sampler2D sampler;

void main(void){
	
	//out_Color = vec4(colour.xyz, 1.0);
	out_Color = texture(sampler, pass_texture_coords) * dot(surface_normal, vec3(0.8, 0.7, 0.8));
	//out_Color = vec4(pass_texture_coords.x, pass_texture_coords.y, 0, 1);

}