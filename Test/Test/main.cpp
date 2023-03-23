#include "MicroMath.h"
#include <cstdio>
#include <string>
#include "VecTypeTest.h"

// FWK - collisions
// mathc - collisions
// glm

void Error(const std::string& msg)
{
	puts(("\tERROR: " + msg + ": fail").c_str());
}

int main(
	[[maybe_unused]] int   argc,
	[[maybe_unused]] char* argv[])
{
	VetTypeTestRun();

	Vec2<float> tt(10.0f, 11.0f);
	Vec2<float> r = DegreesToRadians(tt);
	Vec2<float> r2 = Sin(tt);

	Vec3<float> tt3(10.0f, 11.0f, 12.0f);
	Vec3<float> r3 = DegreesToRadians(tt);
	Vec3<float> r32 = Sin(tt);





}