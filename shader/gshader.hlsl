// ---------------------------------------------------------------
// GSを扱う
// Date 2024/05/09
// Author Keigo Onari
// ---------------------------------------------------------------

// ===========================================
// インクルード
// ===========================================
#include "shaderHeader.hlsli"

// ===========================================
// グローバル変数
// ===========================================

// ===========================================
// 定数
// ===========================================
cbuffer TexScale : register(b0)
{
    float2 texScale;
}

// ===========================================
// GS用構造体
// ===========================================


#define SCREEN_WIDTH (1920.0f)
#define SCREEN_HEIGHT (1080.0f)
#define MAX_VERTEX (4)

// ===========================================
// ジオメトリーシェーダー
// ===========================================
[maxvertexcount(MAX_VERTEX)]
void GSMain(point VSOutput gsIn[1], inout TriangleStream<VSOutput> triStream)
{    
    VSOutput vsOut[MAX_VERTEX];
    
    vsOut[0].position = float4(gsIn[0].worldPos.x - texScale.x, gsIn[0].worldPos.y + texScale.y, 0.0f, 1.0f);
    vsOut[1].position = float4(gsIn[0].worldPos.x + texScale.x, gsIn[0].worldPos.y + texScale.y, 0.0f, 1.0f);
    vsOut[2].position = float4(gsIn[0].worldPos.x - texScale.x, gsIn[0].worldPos.y - texScale.y, 0.0f, 1.0f);
    vsOut[3].position = float4(gsIn[0].worldPos.x + texScale.x, gsIn[0].worldPos.y - texScale.y, 0.0f, 1.0f);
    vsOut[0].uv = float2(0.0f, 0.0f);
    vsOut[1].uv = float2(1.0f, 0.0f);
    vsOut[2].uv = float2(0.0f, 1.0f);
    vsOut[3].uv = float2(1.0f, 1.0f);
    
    //for (int i = 0; i < MAX_VERTEX; i++)
    //{
    //    vsOut[i].position = mul(vsOut[i].position, projectionMat);
    //}
    
    triStream.Append(vsOut[0]);
    triStream.Append(vsOut[1]);
    triStream.Append(vsOut[2]);
    triStream.Append(vsOut[3]);
    
    triStream.RestartStrip();
}