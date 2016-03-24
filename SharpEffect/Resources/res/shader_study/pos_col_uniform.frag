#ifdef GL_ES
varying lowp vec4 v_fragmentColor;
#else
varying vec4 v_fragmentColor;
#endif

void main()
{
    gl_FragColor = v_fragmentColor;
}