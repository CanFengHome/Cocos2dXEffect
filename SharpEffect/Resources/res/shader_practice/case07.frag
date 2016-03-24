#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif

uniform vec2 center;
uniform vec2 resolution;

// 算法详细解释 http://blog.csdn.net/stalendp/article/details/22221597

void main()
{
    float time = CC_Time[1];
    vec2 p = 2.0*(gl_FragCoord.xy-center.xy)/resolution.xy;
    
    // 心形跳动的算法 animate
    float tt = mod(time,1.5)/1.5;
    float ss = pow(tt,.2)*0.5 + 0.5;
    ss -= ss*0.2*sin(tt*6.2831*5.0)*exp(-tt*6.0);
    p *= vec2(0.5,1.5) + ss*vec2(0.5,-0.5);
    
    float a = atan(p.x,p.y)/3.141593;
    float r = length(p);
    
    // shape
    float h = abs(a);
    float d = (13.0*h - 22.0*h*h + 10.0*h*h*h)/(6.0-5.0*h);
    
    // 曲线
    float f = step(r,d);
    

    
    gl_FragColor = vec4(f,0.0,0.0,1.0);

}