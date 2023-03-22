#include "MicroMath.h"
#include <cstdio>
#include <string>

void Error(const std::string& msg)
{
	puts(("\tERROR: " + msg + ": fail").c_str());
}

int main(
	[[maybe_unused]] int   argc,
	[[maybe_unused]] char* argv[])
{
	const float float1 = 102.123f;
	const float float2 = 99.407f;
	const float float3 = 69.544f;
	const float float4 = 36.791f;

	//=========================================================================
	// Vector2 Test
	//=========================================================================
	{
		puts("Vector2 Test:");

		// Test 1
		{
			Vec2<float> vecf(float1);
			if( vecf.x != float1 || vecf.y != float1 )
			{
				Error("Test 1: Vec2(scalar)");
			}
		}

		// Test 2
		{
			Vec2<float> vecf1(float1);
			Vec2<float> vecf2(vecf1);
			if( vecf2.x != float1 || vecf2.y != float1 )
			{
				Error("Test 2: Vec2(Vec2)");
			}
		}

		// Test 3
		{
			Vec2<float> vecf(float1, float2);
			if( vecf.x != float1 || vecf.y != float2 )
			{
				Error("Test 3: Vec2(x, y)");
			}
		}

		// Test 4
		{
			Vec2<float> vecf1(float1, float2);
			Vec2<float> vecf2(float3, float1);
			vecf2 = vecf1;
			if( vecf2.x != float1 || vecf2.y != float2 )
			{
				Error("Test 4: Vec2 = Vec2");
			}
		}

		// Test 5
		{
			Vec2<float> vecf;
			vecf = float1;
			if( vecf.x != float1 || vecf.y != float1 )
			{
				Error("Test 5: Vec2 = scalar");
			}
		}

		// Test 6
		{
			Vec2<float> vecf(float1, float2);
			if( vecf[0] != float1 || vecf[1] != float2 )
			{
				Error("Test 6: Vec2[]");
			}
		}


		// Test 7
		{
			Vec2<float> vecf1(float1, float2);
			Vec2<float> vecf2(float1, float2);

			if( vecf1.x != vecf2.x || vecf1.y != vecf2.y || !(vecf1 == vecf2) )
			{
				Error("Test 7: operator==");
			}
		}

		// Test 8
		{
			Vec2<float> vecf(float1, float2);
			vecf = -vecf;

			if( vecf.x != -float1 || vecf.y != -float2 )
			{
				Error("Test 8: operator-");
			}
		}

#define Vector2OperatorTest(op)  \
		{ \
			Vec2<float> vecf1(float1, float2); \
			Vec2<float> vecf2 = float3 op vecf1; \
			if( vecf2.x != float3 op vecf1.x || vecf2.y != float3 op vecf1.y ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(scalar, type)"); \
			} \
		} { \
			Vec2<float> vecf1(float1, float2); \
			Vec2<float> vecf2 = vecf1 op float3; \
			if( vecf2.x != vecf1.x op float3 || vecf2.y != vecf1.y op float3 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(type, scalar)"); \
			} \
		} { \
			Vec2<float> vecf1(float1, float2); \
			Vec2<float> vecf2(float2, float3); \
			Vec2<float> vecf3 = vecf1 op vecf2; \
			if( vecf3.x != vecf1.x op vecf2.x || vecf3.y != vecf1.y op vecf2.y ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(type, type)"); \
			} \
		} { \
			Vec2<float> vecf1(float1, float2); \
			vecf1 ##op## = float3; \
			if( vecf1.x != float1 op float3 || vecf1.y != float2 op float3 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "=(scalar)"); \
			} \
		} { \
			Vec2<float> vecf1(float1, float2); \
			Vec2<float> vecf2(float2, float3); \
			vecf2 ##op## = vecf1; \
			if( vecf2.x != float2 op float1 || vecf2.y != float3 op float2 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "=(type)"); \
			} \
		}

		Vector2OperatorTest(-);
		Vector2OperatorTest(+);
		Vector2OperatorTest(*);
		Vector2OperatorTest(/);
#undef Vector2OperatorTest
	}

	//=========================================================================
	// Vector3 Test
	//=========================================================================
	{
		puts("Vector3 Test:");

		// Test 1
		{
			Vec3<float> vecf(float1);
			if( vecf.x != float1 || vecf.y != float1 || vecf.z != float1 )
			{
				Error("Test 1: Vec3(scalar)");
			}
		}

		// Test 2
		{
			Vec3<float> vecf1(float1);
			Vec3<float> vecf2(vecf1);
			if( vecf2.x != float1 || vecf2.y != float1 || vecf2.z != float1 )
			{
				Error("Test 2: Vec3(Vec3)");
			}
		}

		// Test 3
		{
			Vec3<float> vecf(float1, float2, float3);
			if( vecf.x != float1 || vecf.y != float2 || vecf.z != float3 )
			{
				Error("Test 3: Vec3(x, y, z)");
			}
		}

		// Test 4
		{
			Vec3<float> vecf1(float1, float2, float3);
			Vec3<float> vecf2(float3, float1, float2);
			vecf2 = vecf1;
			if( vecf2.x != float1 || vecf2.y != float2 || vecf2.z != float3 )
			{
				Error("Test 4: Vec3 = Vec3");
			}
		}

		// Test 5
		{
			Vec3<float> vecf;
			vecf = float1;
			if( vecf.x != float1 || vecf.y != float1 || vecf.z != float1 )
			{
				Error("Test 5: Vec3 = scalar");
			}
		}

		// Test 6
		{
			Vec3<float> vecf(float1, float2, float3);
			if( vecf[0] != float1 || vecf[1] != float2 || vecf[2] != float3 )
			{
				Error("Test 6: Vec3[]");
			}
		}


		// Test 7
		{
			Vec3<float> vecf1(float1, float2, float3);
			Vec3<float> vecf2(float1, float2, float3);

			if( vecf1.x != vecf2.x || vecf1.y != vecf2.y || vecf1.z != vecf2.z || !(vecf1 == vecf2))
			{
				Error("Test 7: operator==");
			}
		}

		// Test 9
		{
			Vec3<float> vecf(float1, float2, float3);
			vecf = -vecf;

			if( vecf.x != -float1 || vecf.y != -float2 || vecf.z != -float3 )
			{
				Error("Test 8: operator-");
			}
		}

#define Vector3OperatorTest(op)  \
		{ \
			Vec3<float> vecf1(float1, float2, float3); \
			Vec3<float> vecf2 = float4 op vecf1; \
			if( vecf2.x != float4 op vecf1.x || vecf2.y != float4 op vecf1.y || vecf2.z != float4 op vecf1.z ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(scalar, type)"); \
			} \
		} { \
			Vec3<float> vecf1(float1, float2, float3); \
			Vec3<float> vecf2 = vecf1 op float4; \
			if( vecf2.x != vecf1.x op float4 || vecf2.y != vecf1.y op float4 || vecf2.z != vecf1.z op float4 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(type, scalar)"); \
			} \
		} { \
			Vec3<float> vecf1(float1, float2, float3); \
			Vec3<float> vecf2(float2, float3, float1); \
			Vec3<float> vecf3 = vecf1 op vecf2; \
			if( vecf3.x != vecf1.x op vecf2.x || vecf3.y != vecf1.y op vecf2.y || vecf3.z != vecf1.z op vecf2.z ) \
			{ \
				Error("Test: operator" + std::string(#op) + "(type, type)"); \
			} \
		} { \
			Vec3<float> vecf1(float1, float2, float3); \
			vecf1 ##op## = float4; \
			if( vecf1.x != float1 op float4 || vecf1.y != float2 op float4 || vecf1.z != float3 op float4 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "=(scalar)"); \
			} \
		} { \
			Vec3<float> vecf1(float1, float2, float3); \
			Vec3<float> vecf2(float2, float3, float1); \
			vecf2 ##op## = vecf1; \
			if( vecf2.x != float2 op float1 || vecf2.y != float3 op float2 || vecf2.z != float1 op float3 ) \
			{ \
				Error("Test: operator" + std::string(#op) + "=(type)"); \
			} \
		}

		Vector3OperatorTest(-);
		Vector3OperatorTest(+);
		Vector3OperatorTest(*);
		Vector3OperatorTest(/ );
#undef Vector3OperatorTest
	}
}