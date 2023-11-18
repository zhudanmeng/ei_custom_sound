/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 01.03.2021 18:56:40

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_ops.h"

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

namespace {

constexpr int kTensorArenaSize = 1600;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_ADD, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[31];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[15];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,637 } };
const TfArray<1, float> quant0_scale = { 1, { 0.044383645057678223, } };
const TfArray<1, int> quant0_zero = { 1, { 9 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 208, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int8_t tensor_data2[8] = { 24, -71, -36, -99, -127, -34, -21, -85, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<1, float> quant2_scale = { 1, { 0.013411333784461021, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int8_t tensor_data3[16] = { -37, -69, -62, -83, -60, -76, -100, 30, 13, 24, 56, -52, -34, -127, -59, -68, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0055494462139904499, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[3] = { -3759, 2858, -180, };
const TfArray<1, int> tensor_dimension4 = { 1, { 3 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00015228657866828144, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[3*208] = { 
  -6, 1, 20, 1, -6, 40, 9, 31, -55, 0, 2, -1, 2, -52, 68, -26, -17, 83, 38, 2, -24, 40, 6, 11, -70, -11, -9, 6, -29, -47, 52, -37, -15, 68, -28, 42, 3, 68, -6, 53, -13, -25, -8, -87, -76, -93, 24, -28, -4, 57, -3, 53, 41, 27, -16, 42, -34, -28, -44, -50, -71, -25, 36, -50, -1, 95, -9, 65, 47, 38, -13, 33, 28, -84, -92, -60, -68, -49, 19, -52, 41, 73, -5, 32, 65, 34, -10, 33, 29, -6, -106, -41, -48, -12, 44, -37, -25, 61, -2, 31, 65, -72, -47, 52, 64, -31, -82, 2, 5, -4, -9, -19, 1, 38, -34, 34, 42, -31, -28, 62, 33, -93, -127, 12, 3, 4, -72, -2, 1, 20, -39, 28, 20, -37, -54, 66, 35, -98, -52, 18, 25, -40, -39, -22, 6, 45, -14, 32, 33, -38, -50, 88, 57, -26, -36, 26, 15, -5, -50, 7, -2, 39, -22, 16, 7, -2, 43, -48, 16, 5, -4, 4, 41, 44, -3, -18, -38, -16, 40, -4, 38, 12, -1, -59, 52, 21, -11, -50, -25, 40, 34, -32, -86, 27, 53, -6, 29, -16, 16, -32, 78, 42, -11, -19, -21, -7, 33, -9, 
  -8, -3, 5, 16, 25, 0, -2, 18, 37, -13, -24, 13, 36, -10, -35, 11, -9, 29, -25, 22, 11, -5, 0, -24, 54, -7, -20, -17, 39, -29, -22, 36, 31, 11, -4, 15, -19, -20, 1, -19, 27, -13, 9, 6, 9, -47, -5, 24, 14, -24, -36, -1, -48, -12, 30, -13, 24, 15, 10, -25, -9, -59, -29, 36, 31, 10, -27, 30, -12, 0, 13, -20, -30, 17, 40, -29, 20, -32, -39, 35, 13, -21, -46, 5, -17, 16, 17, 14, -6, -10, 36, -9, 20, -37, -27, 29, 16, -14, 3, 25, -46, 19, 42, -25, -34, 17, 14, -25, 7, -10, -4, 52, 4, -7, -34, 5, -42, 13, 56, -22, -28, 31, 24, -14, -6, -28, 8, 5, 17, -19, -25, -3, -25, 48, 17, 15, 4, 31, 31, -41, 9, -39, -18, 32, 6, -42, -39, -4, -39, 26, 36, -13, -2, 3, 6, -24, 1, -52, 6, 22, -6, -7, 8, 7, -45, 25, 5, 28, 6, -16, 0, 22, -9, -36, 27, 28, 24, -18, -44, 5, -42, 1, 12, 21, -34, -19, -11, 14, 18, -74, -26, 11, 62, 18, -35, 35, -21, 5, 7, 14, 12, -30, 8, 15, 13, -60, -16, 27, 
  5, -14, -5, -3, 11, -29, -5, -29, 3, 4, 5, -22, -28, 26, -20, -4, -24, -42, 7, -22, 32, -20, -14, 8, -40, 22, 1, 28, -2, 49, -12, -4, -22, -27, 51, -57, 18, -15, -4, -18, -30, 17, 4, 37, 11, 55, -25, 19, -33, -46, 22, -31, -8, -26, 3, -23, -12, 28, 9, 13, 43, 49, 2, -1, -10, -35, 28, -86, -1, -8, 6, -8, -17, 26, 28, 46, 37, 39, -19, 1, -37, -13, 55, -43, -9, -51, 0, -9, -9, 6, 26, 48, 31, 47, 16, -11, -10, -17, 26, -39, 0, 30, 0, 3, -10, 12, -3, 37, 21, 36, -12, -2, -48, -7, 25, -29, 15, 22, -32, -10, -37, 36, 17, 23, 13, 30, 38, -11, -22, 0, 40, -19, 10, -2, -13, -36, -17, 15, 31, 14, 2, 35, 13, -8, -39, -1, 27, -14, 15, -5, 10, -33, 3, 30, 6, 31, -17, 42, 0, 2, -15, 11, 23, -23, 1, -19, -7, -19, 0, 16, 15, -6, 27, -6, 23, -13, 6, -14, 5, -10, 30, -3, -31, -3, -16, 7, 3, 4, 8, 33, -15, 10, 9, -32, -16, -52, -22, -3, 9, 35, -83, -14, 13, -9, -9, 36, 0, -19, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 3,208 } };
const TfArray<1, float> quant5_scale = { 1, { 0.0073753129690885544, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int32_t tensor_data6[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension6 = { 1, { 8 } };
const TfArray<8, float> quant6_scale = { 8, { 0.00024824586580507457, 0.00020450053852982819, 0.00018501041631679982, 0.00021670362912118435, 0.00015832055942155421, 0.0003492786199785769, 0.0002704462967813015, 0.00015915017866063863, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[8*1*3*13] = { 
  /* [0][0][][] */ -103,0,-22,55,74,70,10,-35,-34,22,15,-6,-7, -101,-26,-26,-38,8,28,-25,-16,-43,-15,-2,-3,-7, -127,-19,-5,7,4,-56,-20,-2,16,24,-26,21,27, 
  /* [1][0][][] */ 103,28,-45,-73,25,19,-49,-62,3,-40,-2,-9,-6, 80,-29,-33,-55,12,35,7,6,-21,-10,25,11,0, 127,0,8,-44,20,22,13,-7,-13,-1,-2,23,-10, 
  /* [2][0][][] */ -107,-110,12,-3,-43,12,-20,21,-24,-19,8,51,50, -61,-126,-22,27,-50,-40,29,-43,-1,-2,15,4,38, -31,-127,-89,42,-36,17,68,-33,20,42,5,43,71, 
  /* [3][0][][] */ 51,52,-26,11,-35,-51,22,4,-13,30,2,-39,-24, 57,91,-42,61,-48,-35,-28,41,0,5,-8,10,-20, 88,127,-84,11,-33,-30,-10,25,-22,14,-25,16,-28, 
  /* [4][0][][] */ 51,100,-65,2,77,-31,4,-12,-22,-15,37,-10,-58, 62,22,-124,4,60,-7,73,-44,-39,-16,-19,-14,-34, 88,-31,-80,25,-35,94,51,-127,-44,7,-5,-1,-37, 
  /* [5][0][][] */ -127,15,0,-35,-28,-4,-9,5,5,4,-3,-2,-4, -60,-21,40,57,26,-6,-29,-19,0,-7,-1,6,-2, 105,-19,-49,-11,32,27,8,-14,-13,11,-11,-12,-13, 
  /* [6][0][][] */ -13,-74,-90,-73,-52,-30,8,-6,-17,-19,-21,-10,-32, -53,74,53,80,30,10,33,39,34,12,14,25,5, -127,-51,5,-50,-14,4,12,-4,-30,-19,5,0,24, 
  /* [7][0][][] */ 36,-76,49,-101,-90,89,-6,24,8,-24,-21,14,-1, 127,38,60,-115,-63,74,-49,-16,-15,-6,-23,6,-38, 79,115,87,-93,-47,18,-10,-47,13,-25,-10,-22,-39, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0055931834504008293, 0.0046075652353465557, 0.0041684368625283241, 0.0048825107514858246, 0.0035670923534780741, 0.0078695341944694519, 0.0060933772474527359, 0.003585784463211894, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension8 = { 1, { 16 } };
const TfArray<16, float> quant8_scale = { 16, { 0.00017209164798259735, 0.00025736712268553674, 0.00020490145834628493, 0.00024363644479308277, 0.00016905649681575596, 0.00020499824313446879, 0.00016703293658792973, 0.00026762316701933742, 0.00023641611915081739, 0.00025674549397081137, 0.00016752618830651045, 0.00020568024774547666, 0.00017524859867990017, 0.0002945516025647521, 0.00029431781149469316, 0.00018801515398081392, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(8) int8_t tensor_data9[16*1*3*8] = { 
  /* [0][0][][] */ -28,-2,-41,1,-15,-10,63,-15, -12,-17,-65,-10,-40,-120,25,-13, -67,8,-44,-3,-12,127,-10,5, 
  /* [1][0][][] */ -32,21,-93,-127,-16,-102,-39,59, -11,-16,-31,-100,-104,-10,-14,8, 9,-52,49,-17,-4,12,-26,-60, 
  /* [2][0][][] */ -83,72,-5,6,32,-48,-59,-17, -93,-19,26,37,5,-83,-30,2, -127,12,-32,15,74,-104,-71,11, 
  /* [3][0][][] */ -42,49,-22,-15,44,-68,-55,25, -13,-9,-21,-23,-49,-72,12,26, 29,-127,18,-43,-68,47,25,-39, 
  /* [4][0][][] */ -94,-48,68,-62,24,-55,-57,63, -73,-125,25,-63,19,-33,-52,44, -16,-112,107,127,-46,-57,-58,-74, 
  /* [5][0][][] */ 39,-92,-5,-41,-58,30,12,-62, -24,-76,-44,-21,-14,14,-43,-127, -52,18,-22,-5,96,33,-69,-42, 
  /* [6][0][][] */ 4,7,-1,-82,8,42,5,6, 11,0,-21,-57,6,127,12,-7, -32,5,-19,-25,-14,-44,24,-3, 
  /* [7][0][][] */ 5,-127,25,-11,-49,13,4,-118, -27,-119,-58,36,-23,8,21,-119, -33,-19,-96,26,29,1,-48,-21, 
  /* [8][0][][] */ -38,-48,51,1,-38,-29,-1,-12, -53,-18,-62,85,-64,-85,-1,15, 1,-102,-56,-23,-127,-26,43,-42, 
  /* [9][0][][] */ 4,-32,27,-72,-38,5,-2,-63, -14,-1,6,-125,-32,-2,2,-37, 14,8,29,-127,-54,-25,10,-32, 
  /* [10][0][][] */ 13,-51,-21,-21,-21,29,25,-127, -6,-31,-15,-77,-17,-7,-15,-90, 58,-70,-37,-100,-41,1,19,-65, 
  /* [11][0][][] */ -73,-8,-1,-37,-34,-30,-69,65, -104,30,-77,-18,-24,-80,-22,18, -127,23,-92,40,-14,-100,-82,23, 
  /* [12][0][][] */ -4,-67,-41,-107,-125,21,15,18, -18,-71,-35,-127,-117,4,34,19, -21,43,-28,-76,-74,0,-29,88, 
  /* [13][0][][] */ -115,15,17,26,10,-24,-61,22, -125,-15,22,-9,2,-76,-47,-2, -127,12,16,45,28,-44,-47,10, 
  /* [14][0][][] */ 6,-4,-30,2,-5,26,-13,-127, -20,11,-12,-11,64,-4,-6,-76, -12,19,-19,-48,12,-23,-42,2, 
  /* [15][0][][] */ -15,15,-35,8,-13,-11,-43,-26, -22,-7,-35,-11,-23,-11,127,-25, -4,13,-20,-112,-40,-2,-13,-8, 
};
const TfArray<4, int> tensor_dimension9 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant9_scale = { 16, { 0.0050457129254937172, 0.0075459829531610012, 0.0060076937079429626, 0.0071434006094932556, 0.0049567227251827717, 0.006010531447827816, 0.004897391889244318, 0.0078466888517141342, 0.0069317012093961239, 0.007527756504714489, 0.0049118539318442345, 0.0060305278748273849, 0.0051382742822170258, 0.0086362287402153015, 0.0086293742060661316, 0.005512588657438755, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(8) int32_t tensor_data10[4] = { 1, 1, 49, 13, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[3] = { 1, 49, 8, };
const TfArray<1, int> tensor_dimension11 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data12[4] = { 1, 49, 1, 8, };
const TfArray<1, int> tensor_dimension12 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data13[4] = { 1, 1, 25, 8, };
const TfArray<1, int> tensor_dimension13 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data14[3] = { 1, 25, 16, };
const TfArray<1, int> tensor_dimension14 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data15[4] = { 1, 25, 1, 16, };
const TfArray<1, int> tensor_dimension15 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,49,13 } };
const TfArray<1, float> quant16_scale = { 1, { 0.044383645057678223, } };
const TfArray<1, int> quant16_zero = { 1, { 9 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,49,8 } };
const TfArray<1, float> quant17_scale = { 1, { 0.073194883763790131, } };
const TfArray<1, int> quant17_zero = { 1, { 4 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<3, int> tensor_dimension18 = { 3, { 1,49,8 } };
const TfArray<1, float> quant18_scale = { 1, { 0.073194883763790131, } };
const TfArray<1, int> quant18_zero = { 1, { 4 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<3, int> tensor_dimension19 = { 3, { 1,49,8 } };
const TfArray<1, float> quant19_scale = { 1, { 0.034106507897377014, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<4, int> tensor_dimension20 = { 4, { 1,49,1,8 } };
const TfArray<1, float> quant20_scale = { 1, { 0.034106507897377014, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<4, int> tensor_dimension21 = { 4, { 1,25,1,8 } };
const TfArray<1, float> quant21_scale = { 1, { 0.034106507897377014, } };
const TfArray<1, int> quant21_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<4, int> tensor_dimension22 = { 4, { 1,1,25,8 } };
const TfArray<1, float> quant22_scale = { 1, { 0.034106507897377014, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfArray<4, int> tensor_dimension23 = { 4, { 1,1,25,16 } };
const TfArray<1, float> quant23_scale = { 1, { 0.11685432493686676, } };
const TfArray<1, int> quant23_zero = { 1, { 79 } };
const TfLiteAffineQuantization quant23 = { (TfLiteFloatArray*)&quant23_scale, (TfLiteIntArray*)&quant23_zero, 0 };
const TfArray<3, int> tensor_dimension24 = { 3, { 1,25,16 } };
const TfArray<1, float> quant24_scale = { 1, { 0.11685432493686676, } };
const TfArray<1, int> quant24_zero = { 1, { 79 } };
const TfLiteAffineQuantization quant24 = { (TfLiteFloatArray*)&quant24_scale, (TfLiteIntArray*)&quant24_zero, 0 };
const TfArray<3, int> tensor_dimension25 = { 3, { 1,25,16 } };
const TfArray<1, float> quant25_scale = { 1, { 0.020648151636123657, } };
const TfArray<1, int> quant25_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant25 = { (TfLiteFloatArray*)&quant25_scale, (TfLiteIntArray*)&quant25_zero, 0 };
const TfArray<4, int> tensor_dimension26 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant26_scale = { 1, { 0.020648151636123657, } };
const TfArray<1, int> quant26_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant26 = { (TfLiteFloatArray*)&quant26_scale, (TfLiteIntArray*)&quant26_zero, 0 };
const TfArray<4, int> tensor_dimension27 = { 4, { 1,13,1,16 } };
const TfArray<1, float> quant27_scale = { 1, { 0.020648151636123657, } };
const TfArray<1, int> quant27_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant27 = { (TfLiteFloatArray*)&quant27_scale, (TfLiteIntArray*)&quant27_zero, 0 };
const TfArray<2, int> tensor_dimension28 = { 2, { 1,208 } };
const TfArray<1, float> quant28_scale = { 1, { 0.020648151636123657, } };
const TfArray<1, int> quant28_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant28 = { (TfLiteFloatArray*)&quant28_scale, (TfLiteIntArray*)&quant28_zero, 0 };
const TfArray<2, int> tensor_dimension29 = { 2, { 1,3 } };
const TfArray<1, float> quant29_scale = { 1, { 0.090858563780784607, } };
const TfArray<1, int> quant29_zero = { 1, { -8 } };
const TfLiteAffineQuantization quant29 = { (TfLiteFloatArray*)&quant29_scale, (TfLiteIntArray*)&quant29_zero, 0 };
const TfArray<2, int> tensor_dimension30 = { 2, { 1,3 } };
const TfArray<1, float> quant30_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant30_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant30 = { (TfLiteFloatArray*)&quant30_scale, (TfLiteIntArray*)&quant30_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,10 } };
const TfArray<1, int> outputs0 = { 1, { 16 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 16,7,6 } };
const TfArray<1, int> outputs1 = { 1, { 17 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 17,11 } };
const TfArray<1, int> outputs2 = { 1, { 18 } };
const TfLiteAddParams opdata3 = { kTfLiteActRelu };
const TfArray<2, int> inputs3 = { 2, { 18,2 } };
const TfArray<1, int> outputs3 = { 1, { 19 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 19,12 } };
const TfArray<1, int> outputs4 = { 1, { 20 } };
const TfLitePoolParams opdata5 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs5 = { 1, { 20 } };
const TfArray<1, int> outputs5 = { 1, { 21 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 21,13 } };
const TfArray<1, int> outputs6 = { 1, { 22 } };
const TfLiteConvParams opdata7 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs7 = { 3, { 22,9,8 } };
const TfArray<1, int> outputs7 = { 1, { 23 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 23,14 } };
const TfArray<1, int> outputs8 = { 1, { 24 } };
const TfLiteAddParams opdata9 = { kTfLiteActRelu };
const TfArray<2, int> inputs9 = { 2, { 24,3 } };
const TfArray<1, int> outputs9 = { 1, { 25 } };
const TfLiteReshapeParams opdata10 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs10 = { 2, { 25,15 } };
const TfArray<1, int> outputs10 = { 1, { 26 } };
const TfLitePoolParams opdata11 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs11 = { 1, { 26 } };
const TfArray<1, int> outputs11 = { 1, { 27 } };
const TfLiteReshapeParams opdata12 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs12 = { 2, { 27,1 } };
const TfArray<1, int> outputs12 = { 1, { 28 } };
const TfLiteFullyConnectedParams opdata13 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs13 = { 3, { 28,5,4 } };
const TfArray<1, int> outputs13 = { 1, { 29 } };
const TfLiteSoftmaxParams opdata14 = { 1 };
const TfArray<1, int> inputs14 = { 1, { 29 } };
const TfArray<1, int> outputs14 = { 1, { 30 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension0, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 624, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data12, (TfLiteIntArray*)&tensor_dimension12, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data13, (TfLiteIntArray*)&tensor_dimension13, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data14, (TfLiteIntArray*)&tensor_dimension14, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data15, (TfLiteIntArray*)&tensor_dimension15, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension17, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension19, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension23, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant23))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension24, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant24))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension25, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant25))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension26, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant26))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension27, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant27))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension28, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant28))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 208, (TfLiteIntArray*)&tensor_dimension29, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant29))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension30, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant30))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_ADD, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_ADD, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs11, (TfLiteIntArray*)&outputs11, const_cast<void*>(static_cast<const void*>(&opdata11)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs12, (TfLiteIntArray*)&outputs12, const_cast<void*>(static_cast<const void*>(&opdata12)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs13, (TfLiteIntArray*)&outputs13, const_cast<void*>(static_cast<const void*>(&opdata13)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs14, (TfLiteIntArray*)&outputs14, const_cast<void*>(static_cast<const void*>(&opdata14)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    *ptr = malloc(bytes);
    if (*ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return kTfLiteError;
    }
    overflow_buffers.push_back(*ptr);
    return kTfLiteOk;
  }

  current_location -= bytes;

  *ptr = current_location;
  return kTfLiteOk;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  TfLiteStatus s = AllocatePersistentBuffer(ctx, b.bytes, &b.ptr);
  if (s != kTfLiteOk) {
    return s;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}
} // namespace

  TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 31;
  for(size_t i = 0; i < 31; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = *tflite::ops::micro::Register_RESHAPE();
  registrations[OP_CONV_2D] = *tflite::ops::micro::Register_CONV_2D();
  registrations[OP_ADD] = *tflite::ops::micro::Register_ADD();
  registrations[OP_MAX_POOL_2D] = *tflite::ops::micro::Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = *tflite::ops::micro::Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = *tflite::ops::micro::Register_SOFTMAX();

  for(size_t i = 0; i < 15; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 15; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  30, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 15; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}