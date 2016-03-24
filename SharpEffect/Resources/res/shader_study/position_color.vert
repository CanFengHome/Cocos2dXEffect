attribute vec4 a_position;
attribute vec4 a_color;

varying vec4 fragColor;

void main()
{
    gl_Position = CC_MVPMatrix * a_position;
    fragColor = a_color;
}