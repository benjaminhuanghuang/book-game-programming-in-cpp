
## Window
### SDL API


### GLEW (OpenGL Extension Wrangler Library)
OpenGL supports backward compatibility with an extension system. 
Normally, you must query any extensions you want manually, which is tedious. 
To simplify this process, you can use an open source library called the OpenGL Extension Wrangler Library (GLEW).

## Triangle Basics

### Vertex and Index Buffers

The solution to this issue has two parts. 
First, you create a vertex buffer that contains only the unique coordinates used by the 3D geometry. 
Then, to specify the vertices of each triangle, you index into this vertex buffer (much like indexing into an array).