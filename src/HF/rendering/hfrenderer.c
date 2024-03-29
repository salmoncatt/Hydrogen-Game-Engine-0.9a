#include "hfrenderer.h"

m4f hf_renderer_proj_mat = {};
m4f hf_renderer_ortho;
m4f hf_renderer_pixel_ortho;

b8 hf_renderer_wireframe_active = 0;
f32 hf_aspect_ratio = 0;
u32 hf_window_w;
u32 hf_window_h;

hf_shader hf_default_shader = {};;

hf_camera hf_renderer_camera = {};

void hf_renderer_init(hf_app* app) {
    hf_log("[HF] initializing HF Renderer...\n");
    
    char* cpu = hf_get_cpu_name();
    hf_log("[HF] OpenGL Vendor: [%s]\n", glGetString(GL_VENDOR));
    hf_log("[HF] OpenGL Version: [%s]\n", glGetString(GL_VERSION));
    hf_log("[HF] GPU: [%s]\n", glGetString(GL_RENDERER));
    hf_log("[HF] CPU: [%s]\n", cpu);
    hf_free(cpu);
    
    
    hf_renderer_proj_mat = hf_perspective_m4f(app->window.w, app->window.h, 90, 0.1f, 1000);
    hf_renderer_pixel_ortho = hf_ortho_m4f(0, app->window.w, app->window.h, 0, -1, 1);
    
    hf_aspect_ratio = app->window.w / app->window.h;
    hf_window_w = app->window.w;
    hf_window_h = app->window.h;
    
    if (app->window.w < app->window.w)
        hf_renderer_ortho = hf_ortho_m4f(0, 2, -2 / hf_aspect_ratio, 0, -1, 1);
    else
        hf_renderer_ortho = hf_ortho_m4f(0, 2 * hf_aspect_ratio, -2, 0, -1, 1);
    
    glViewport(0, 0, app->window.w, app->window.h);
    
    hf_default_shader.name = "HF Default Shader";
    hf_shader_create(&hf_default_shader, "../res/shaders/vertex.glsl", "../res/shaders/fragment.glsl");
    
    
    //doesn't render faces that face away and thus can't see
    glEnable(GL_BACK);
    glEnable(GL_CULL_FACE);
    
    hf_log("[HF] initialized HF Renderer\n\n");
}

void hf_renderer_update(hf_app* app){
    //hf_renderer_update_2d();
    
    hf_renderer_proj_mat = hf_perspective_m4f(app->window.w, app->window.h, 90, 0.1f, 1000);
    hf_renderer_pixel_ortho = hf_ortho_m4f(0, app->window.w, app->window.h, 0, -1, 1);
    
    hf_aspect_ratio = app->window.w / app->window.h;
    hf_window_w = app->window.w;
    hf_window_h = app->window.h;
    
    
    if (app->window.w < app->window.w)
        hf_renderer_ortho = hf_ortho_m4f(0, 2, -2 / hf_aspect_ratio, 0, -1, 1);
    else
        hf_renderer_ortho = hf_ortho_m4f(0, 2 * hf_aspect_ratio, -2, 0, -1, 1);
    
    
    glViewport(0, 0, app->window.w, app->window.h);
    
    //printf("[%f %f %f]\n", hf_renderer_cam.transform.pos.x, hf_renderer_cam.transform.pos.y, hf_renderer_cam.transform.pos.z);
    
    //hf_update_debug_camera(&hf_renderer_cam);
}

void hf_renderer_destroy(hf_app* app) {
    hf_shader_destroy(&hf_default_shader);
    hf_log("[HF] destroyed HF Renderer\n");
}

void hf_render_mesh(hf_mesh* mesh, hf_shader* shader, hf_transform* transform){
    glBindVertexArray(mesh->vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    //glEnableVertexAttribArray(3);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ibo);
    
    hf_shader_bind(shader);
    hf_shader_set_uniform_v3f(shader, "pos", &transform->pos);
    
    if(mesh->texture.image.data != NULL){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, mesh->texture.texture_id);
    }
    
    m4f transformation = hf_transformation_m4f(transform->pos, transform->rot, transform->scale);
    m4f view = hf_view_m4f(hf_renderer_camera.pos, hf_renderer_camera.rot);
    hf_shader_set_uniform_m4f(shader, "transform", &transformation);
    hf_shader_set_uniform_m4f(shader, "view", &view);
    hf_shader_set_uniform_m4f(shader, "projection", &hf_renderer_proj_mat);
    //position
    
    if(hf_array_size(mesh->indices) > 0)
        glDrawElements(GL_TRIANGLES, hf_array_size(mesh->indices), GL_UNSIGNED_INT, 0);
    else if(hf_array_size(mesh->vertices) > 0)
        glDrawArrays(GL_TRIANGLES, 0, (int)(hf_array_size(mesh->vertices) / mesh->type));
    
    
    hf_shader_unbind();
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    //glDisableVertexAttribArray(3);
    glBindVertexArray(0);
}

void hf_renderer_set_wireframe_mode(b8 mode){
    hf_renderer_wireframe_active = mode;
    glPolygonMode(GL_FRONT_AND_BACK, mode ? GL_LINE : GL_FILL);
}

void hf_renderer_toggle_wireframe(){
    hf_renderer_set_wireframe_mode(!hf_renderer_wireframe_active);
}