attribute vec4 vertexPosition;

void main()
{
    gl_Position = CC_MVPMatrix * vertexPosition;
}