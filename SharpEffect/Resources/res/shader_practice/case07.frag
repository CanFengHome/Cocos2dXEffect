#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif

uniform sampler2D u_Texture;
uniform float u_MoveLen;

void main()
{
    vec4 uBottomColor = texture2D(u_Texture, v_texCoord);
    if (uBottomColor.w < 0.00001)
    {
        discard;
    }
    
    vec2 fragTextureCoord = vec2(v_texCoord.x + u_MoveLen, v_texCoord.y);
    gl_FragColor = texture2D(CC_Texture0, fragTextureCoord) * v_color;
}