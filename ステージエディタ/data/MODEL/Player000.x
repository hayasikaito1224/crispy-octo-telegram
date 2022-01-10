xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 70;
 -0.00000;0.07577;0.00000;,
 -5.76407;2.25999;-5.76407;,
 -0.00000;2.25999;-8.15162;,
 -0.00000;0.07577;0.00000;,
 -8.15163;2.25999;0.00000;,
 -0.00000;0.07577;0.00000;,
 -5.76407;2.25999;5.76407;,
 -0.00000;0.07577;0.00000;,
 -0.00000;2.25999;8.15162;,
 -0.00000;0.07577;0.00000;,
 5.76407;2.25999;5.76407;,
 -0.00000;0.07577;0.00000;,
 8.15162;2.25999;-0.00000;,
 -0.00000;0.07577;0.00000;,
 5.76407;2.25999;-5.76407;,
 -0.00000;0.07577;0.00000;,
 -0.00000;2.25999;-8.15162;,
 -9.98366;8.22739;-9.98366;,
 -0.00000;8.22739;-14.11903;,
 -14.11903;8.22739;0.00000;,
 -9.98366;8.22739;9.98366;,
 0.00000;8.22739;14.11903;,
 9.98366;8.22739;9.98366;,
 14.11903;8.22739;-0.00000;,
 9.98366;8.22739;-9.98366;,
 -0.00000;8.22739;-14.11903;,
 -11.52814;16.37902;-11.52814;,
 0.00000;16.37902;-16.30325;,
 -16.30325;16.37902;0.00000;,
 -11.52814;16.37902;11.52814;,
 0.00000;16.37902;16.30325;,
 11.52814;16.37902;11.52814;,
 16.30325;16.37901;-0.00000;,
 11.52814;16.37902;-11.52814;,
 0.00000;16.37902;-16.30325;,
 -9.98366;24.53064;-9.98366;,
 0.00000;24.53064;-14.11903;,
 -14.11903;24.53064;0.00000;,
 -9.98366;24.53064;9.98366;,
 0.00000;24.53064;14.11903;,
 9.98366;24.53064;9.98366;,
 14.11903;24.53064;-0.00000;,
 9.98366;24.53064;-9.98366;,
 0.00000;24.53064;-14.11903;,
 -5.76407;30.49806;-5.76407;,
 0.00000;30.49806;-8.15163;,
 -8.15162;30.49806;0.00000;,
 -5.76407;30.49806;5.76407;,
 0.00000;30.49806;8.15163;,
 5.76407;30.49806;5.76407;,
 8.15163;30.49806;-0.00000;,
 5.76407;30.49806;-5.76407;,
 0.00000;30.49806;-8.15163;,
 0.00000;30.49806;-8.15163;,
 -5.76407;30.49806;-5.76407;,
 0.00000;32.68225;0.00000;,
 -8.15162;30.49806;0.00000;,
 0.00000;32.68225;0.00000;,
 -5.76407;30.49806;5.76407;,
 0.00000;32.68225;0.00000;,
 0.00000;30.49806;8.15163;,
 0.00000;32.68225;0.00000;,
 5.76407;30.49806;5.76407;,
 0.00000;32.68225;0.00000;,
 8.15163;30.49806;-0.00000;,
 0.00000;32.68225;0.00000;,
 5.76407;30.49806;-5.76407;,
 0.00000;32.68225;0.00000;,
 0.00000;30.49806;-8.15163;,
 0.00000;32.68225;0.00000;;
 
 48;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;36,35,44,45;,
 4;35,37,46,44;,
 4;37,38,47,46;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 3;53,54,55;,
 3;54,56,57;,
 3;56,58,59;,
 3;58,60,61;,
 3;60,62,63;,
 3;62,64,65;,
 3;64,66,67;,
 3;66,68,69;;
 
 MeshMaterialList {
  2;
  48;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;0.550000;;
   5.000000;
   0.160000;0.160000;0.160000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.031373;1.000000;;
   5.000000;
   0.160000;0.160000;0.160000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  42;
  -0.000000;-1.000000;0.000000;,
  0.000000;-0.868389;-0.495883;,
  -0.350642;-0.868389;-0.350642;,
  -0.495883;-0.868389;0.000000;,
  -0.350642;-0.868389;0.350642;,
  0.000000;-0.868389;0.495883;,
  0.350642;-0.868389;0.350642;,
  0.495883;-0.868389;-0.000000;,
  0.350642;-0.868389;-0.350642;,
  0.000000;-0.503834;-0.863800;,
  -0.610799;-0.503834;-0.610799;,
  -0.863800;-0.503834;0.000000;,
  -0.610799;-0.503834;0.610799;,
  0.000000;-0.503834;0.863800;,
  0.610799;-0.503834;0.610799;,
  0.863800;-0.503834;-0.000000;,
  0.610799;-0.503834;-0.610799;,
  0.000000;0.000000;-1.000000;,
  -0.707107;0.000000;-0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;0.707107;,
  0.000000;0.000000;1.000000;,
  0.707107;0.000000;0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;-0.707107;,
  0.000000;0.503834;-0.863801;,
  -0.610799;0.503834;-0.610799;,
  -0.863801;0.503834;0.000000;,
  -0.610799;0.503834;0.610799;,
  0.000000;0.503834;0.863801;,
  0.610799;0.503834;0.610799;,
  0.863801;0.503833;-0.000000;,
  0.610799;0.503834;-0.610799;,
  0.000000;0.868390;-0.495882;,
  -0.350642;0.868390;-0.350642;,
  -0.495882;0.868390;0.000000;,
  -0.350642;0.868390;0.350642;,
  0.000000;0.868390;0.495883;,
  0.350642;0.868390;0.350642;,
  0.495883;0.868390;-0.000000;,
  0.350642;0.868390;-0.350642;,
  0.000000;1.000000;-0.000000;;
  48;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  3;33,34,41;,
  3;34,35,41;,
  3;35,36,41;,
  3;36,37,41;,
  3;37,38,41;,
  3;38,39,41;,
  3;39,40,41;,
  3;40,33,41;;
 }
 MeshTextureCoords {
  70;
  0.062500;0.000000;,
  0.125000;0.166667;,
  0.000000;0.166667;,
  0.187500;0.000000;,
  0.250000;0.166667;,
  0.312500;0.000000;,
  0.375000;0.166667;,
  0.437500;0.000000;,
  0.500000;0.166667;,
  0.562500;0.000000;,
  0.625000;0.166667;,
  0.687500;0.000000;,
  0.750000;0.166667;,
  0.812500;0.000000;,
  0.875000;0.166667;,
  0.937500;0.000000;,
  1.000000;0.166667;,
  0.125000;0.333333;,
  0.000000;0.333333;,
  0.250000;0.333333;,
  0.375000;0.333333;,
  0.500000;0.333333;,
  0.625000;0.333333;,
  0.750000;0.333333;,
  0.875000;0.333333;,
  1.000000;0.333333;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.666667;,
  0.000000;0.666667;,
  0.250000;0.666667;,
  0.375000;0.666667;,
  0.500000;0.666667;,
  0.625000;0.666667;,
  0.750000;0.666667;,
  0.875000;0.666667;,
  1.000000;0.666667;,
  0.125000;0.833333;,
  0.000000;0.833333;,
  0.250000;0.833333;,
  0.375000;0.833333;,
  0.500000;0.833333;,
  0.625000;0.833333;,
  0.750000;0.833333;,
  0.875000;0.833333;,
  1.000000;0.833333;,
  0.000000;0.833333;,
  0.125000;0.833333;,
  0.062500;1.000000;,
  0.250000;0.833333;,
  0.187500;1.000000;,
  0.375000;0.833333;,
  0.312500;1.000000;,
  0.500000;0.833333;,
  0.437500;1.000000;,
  0.625000;0.833333;,
  0.562500;1.000000;,
  0.750000;0.833333;,
  0.687500;1.000000;,
  0.875000;0.833333;,
  0.812500;1.000000;,
  1.000000;0.833333;,
  0.937500;1.000000;;
 }
}
