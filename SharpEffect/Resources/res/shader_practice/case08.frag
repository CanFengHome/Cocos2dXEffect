#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif
uniform vec2 u_TexUV;

float timeFactor = 2.0;
float texFactor = 6.28;
float ampFactor = 0.03;

vec2 center = vec2(0.5, 0.5);
float boundTransparent(vec2 uv, float alpha)
{
    float transparentValue = alpha;
    transparentValue = step(0.0, uv.x) * transparentValue;
    transparentValue = step(uv.x, 1.0) * transparentValue;
    transparentValue = step(0.0, uv.y) * transparentValue;
    transparentValue = step(uv.y, 1.0) * transparentValue;
    return transparentValue;
}

void main()
{
    vec2 p = (v_texCoord-center)*1.0;
    // 中心点左侧要取-1
    float dirX = sign(p.x);
    float dirY = sign(p.y);
    
    float animationFactor = CC_Time[1]*timeFactor;
    
    // 避免两个波之间有突出的尖 abs(cos(angle)) 保证了余弦图形都在轴的一侧
    float offsetX = max(abs(cos(v_texCoord.y*texFactor + animationFactor)*ampFactor), 0.005)*dirX;
    float offsetY = max(abs(cos(v_texCoord.x*texFactor + animationFactor)*ampFactor), 0.005)*dirY;

//    float offsetX = abs(cos(v_texCoord.y*texFactor + animationFactor)*ampFactor)*dirX;
//    float offsetY = abs(cos(v_texCoord.x*texFactor + animationFactor)*ampFactor)*dirY;
    
    vec2 uv = v_texCoord + vec2(offsetX, offsetY);
    vec4 color = texture2D(CC_Texture0, uv);
    float alpha = boundTransparent(uv, color.a);
    gl_FragColor = color * alpha;
}










