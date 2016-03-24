attribute vec4 a_position;
uniform vec4 u_color;

#ifdef GL_ES
    varying lowp vec4 v_fragmentColor;
#else
    varying vec4 v_fragmentColor;
#endif

void main()
{
    gl_Position = CC_MVPMatrix * a_position;
    v_fragmentColor = u_color;
}