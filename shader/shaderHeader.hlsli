
struct VSInput
{
    float4 position : POSITION;
    float2 uv       : TEXCOORD;
};

struct VSOutput
{
    float4 position : SV_POSITION;
    float2 uv       : TEXCOORD0;
    float4 worldPos : TEXCOORD1;
};

struct PSInput
{
    float4 position : SV_POSITION;
    float2 uv       : TEXCOORD0;
    float4 worldPos : TEXCOORD1;
};