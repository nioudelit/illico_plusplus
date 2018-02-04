precision highp float

// Recevoir Texture via OF
uniform sampler2D tex0;
uniform float h;
uniform float s;
uniform float b;

//Position envoyees par le vertex shader
attribute vec2 varyingtexcoord;

//Notre fragment haut en couleurs
//out vec4 outputColor;

vec3 rgb2hsv(vec3 c){
    //https://stackoverflow.com/questions/15095909/from-rgb-to-hsv-in-opengl-glsl

    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

void main(){

	vec4 col = texture2D(tex0, varyingtexcoord);
	vec3 vertReference = vec3(0.0, 1.0, 0.0);
	vertReference = rgb2hsv(vertReference);

	vec3 texColorHSB = rgb2hsv(col.xyz);
	if(distance(texColorHSB.x, vertReference.x) <= h && 
	   distance(texColorHSB.y, vertReference.y ) <= s &&
	   distance(texColorHSB.z, vertReference.z) >= b)
        	discard;
	
	gl_FragColor = vec4(col);

	//float somme = col.r + col.g + col.b;
	//float bright = somme * 0.33333;
	//outputColor = vec4(vec3(bright), col.a);
}
