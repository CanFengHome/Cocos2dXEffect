#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif
void main()
{
    vec4 resultColor = texture2D(CC_Texture0,v_texCoord)*v_color;
    resultColor *= vec4(0.8,0.8,0.8,1.0);
    resultColor.y += 0.2 * resultColor.w;
    gl_FragColor = resultColor;
}