#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif

float radius = 1.0;//旋转的半径
float angle = 2.0;//旋转的角度

// 旋涡的计算函数
vec2 vortex(vec2 uv)
{
    angle += CC_Time[1];
    if (angle > 360.0)
    {
        angle -= 360.0;
    }
    //先减去贴图中心点的纹理坐标,这样是方便旋转计算
    uv -= vec2(0.5, 0.5);
    //计算当前坐标与中心点的距离。
    float dist = length(uv);
    //计算出旋转的百分比
    float percent = (radius - dist) / radius;
    if ( percent <= 1.0 && percent >= 0.0) //小于半径的区域才进行旋转
    {
        //通过sin,cos来计算出旋转后的位置
        float theta = percent * percent * angle * 0.5;
        float s = sin(theta);
        float c = cos(theta);
        uv = vec2(dot(uv, vec2(c, -s)), dot(uv, vec2(s, c)));
    }
    //再加上贴图中心点的纹理坐标，这样才正确。
    uv += vec2(0.5, 0.5);
    return uv;
}

void main()
{
    gl_FragColor = texture2D(CC_Texture0, vortex(v_texCoord));
}
