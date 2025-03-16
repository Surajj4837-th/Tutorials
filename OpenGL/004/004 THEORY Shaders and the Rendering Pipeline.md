### Rendering Pipeline
1. It is a series of stages that take place in order to render an image on the screen.
2. Five of these stages are programmable via **Shaders**. These are vertex shader, fragment shader, geometry shader, tessellation shader and compute shader.
2. Shaders are pieces of code written in GLSL(OpenGL Shading Language), or HLSL(High0level shading language) if you are using Direct3D.
2. GLSL is based on C.
2. Rendering pipeline stages:
    1. Vertex specifications.
    2. Vertex shader (programmable)
    3. Tessellataion (programmable)
    4. Geometry shader (programmable)
    5. Vertex post-processing
    6. Primitive assembly
    7. Rasterization
    8. Fragment shader (programmable)
    9. Per-sample opertaions

### Vertex specifications
1. A **vertex** (vertices - plural) is a point in space, usually defined with x, y and z coordinate.
1. A **primitive** is a simple shape defined using one or more vertices.
1. Usually we use primitive as triangle but we can also use points, lines and quads. Triangle is made up of 3 vertices. Lines are usually used for drawing a wireframe. Quads are rarely used.
1. **Vertex specification**: setting up the data of the vertices for hte primitive we want to render.
1. Done in the application itself for all the vertices. It will be stored on the RAM of the graphics card. 
1. It uses 2 main things: VAOs (vertex array objects) and VBOs (vertex buffer objects).
1. VAO defines what data a vertex has like position, color, texture, normals, etc.
1. VBO defines the data itself.
1. Attribute pointers define where and how shaders can access vertex data.

#### Creating a VAO/VBO
1. Generate a VAO ID. 
1. Bind the VAO with that ID.
1. Generate a VBO ID.
1. Bind the VBO with that ID (now you are working on the chosen VBO attached to the chosen VAO).
1. Attach the vertex data to the VBO.
1. Define the attribute pointer formatting.
1. Enable the attribute pointer.
1. Unbind the VAO and VBO, ready for the next object to be bound.

#### Initiating draw
1. Activate shader program you want to use. This will be a predefined set of code and programmer can choose which one to use.
1. Bind VAO of the object you want to draw.
1. Call glDrawArrays, which initiates the rest of the pipeline.

### Vertex shader
1. Handles vertices individually.
1. It is not optional.
1. Most store the final position in gl_Position as it isused by later stages.
1. Can specify additional outputs that can be picked up and used by user defined shaders later in pipeline. Additional outputs can be color of shader.
1. Inputs to the shader consist of vertex data itself.

Example:
```C++
#version 330
layout (location = 0) in vec3 pos;

void main()
{
    gl_position = vec4(pos, 1.0);
}
```
OpenGL version has to be defined on top. *in* keyword means input. *vec3* means vector of 3 elements, similarly *vec4*.


### Tessellation
1. It allows to devide up the data in to smaller primitives.
1. Relatively new shader type, appeared in OpenGL 4.0.
1. It can be used to add higher levels of detail dynalically.

### Geometry shader
1. Vertex shader handles vertices, geometry shader handles premitives (group of vertices).
1. It takes premitives and then outputs their vertices to create the given primitive or even new primitives.
1. It can alter the data given to it to modify given primitives or even create new ones.
1. It can even alter the primitive type (points, lines, triangles, etc).

### Vertex post-processing
1. Transform feedback (optional, if enabeled):
    1. Result of vertex and geometry stages saved to buffers for later use. This is useful for repetitive object.
2. Clipping:
    1. Primitives that won't be visible will be removed (No need to draw hidden things).
    2. Positions converted from clip-space to window-space.

### Primitive assembly
1. Vertices are converted to a series of premitives.
1. So if rendering triangles, 6 vertices would become 2 triangles (3 vertices each).
1. Face culling also happens. It is the removal of primitives that can't be seen, or are facing "away" from the viewer. We don't want to draw something if we can't see it.

### Rasterization
1. Converts premitives into fragments.
1. Fragments are the pieces of data for each pixel, obtained from the rasterization process.
1. Fragment data will be interpolated based on it's position relative to each vertex.


### Fragment shader
1. handles data for each fragment.
1. It is optional but its rare to not use it. Exceptions are cases where only depth or stencil data is required (more on depth data later).
1. Most important output is the color of the pixel that the fragment covers. The fragment shader will be handeling all the lighting in our program, all of the texturing, all of the shadows, etc.
1. Simplest OpenGL programs usually have a vertex shader and a fragment shader.
Example:
```C++
#version 330
out vec4 color;

void main()
{
    color = vec4(1.0, 0.0, 0.0, 1.0);   //r,g,b,alpha
{
```

### Per-sample opertaions
1. This is a series of tests to see if the fragment should be drawn.
1. Most important test: depth test. It determines if something is in front of the point being drawn.
1. Color blending: using defined operations, fragment colors are blended together with overlapping fragments. It is usually used to handle transparent objects, like windows.
1. Fragment data is written to currently bound Framebuffer(usually the default buffer).
1. Lastly, in the application code, the user usually defines a buffer swap here, putting the newly updated Framebuffer to the front.

### Shaders
1. Shader programs are a group of shaders (vertex, tessellation, geometry, fragment, etc.) associated with one another.
1. They are created in OpenGL via a series of functions.

### Creating a shader program
1. Create an empty program.
1. Create empty shader.
1. Attach a shader source code to shaders.
1. Compile shaders.
1. Attach shaders to program.
1. Link programs (create executalbels from shaders and link them together).
1. Validate program (optional but highly recommended since debugging shaders is tough).

### Using a shader program
1. When you create a shader, an ID is given(like VAOs and VBOs).
1. Call glUseProgram(shaderID).
1. All draw calls from then on will use that shader, glUseProgram is used on a new shaderID, or on '0' (meaning no shader).