#ifdef GL_ES
varying mediump vec2 v_texCoord;
varying lowp vec4 v_color;
#else
varying vec2 v_texCoord;
varying vec4 v_color;
#endif

uniform vec2 u_center;
uniform float u_radius;

// 算法详细解释 http://www.cocoachina.com/bbs/read.php?tid-228939.html

void main()
{
    float dist = distance(gl_FragCoord.xy, u_center);
    // x3 的图形在【0,1】之间，开始比较缓，接近1时，变换特别快
    float f = smoothstep(0.0,1.0,1.0-pow(dist/u_radius,3.0));
    
    gl_FragColor = vec4(f,0.0,0.0,1.0);
}