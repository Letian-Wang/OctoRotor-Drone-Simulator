/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c32_juecefinishi.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "juecefinishi_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c32_debug_family_names[7] = { "canshu", "nargin", "nargout",
  "u1", "u2", "u3", "y" };

/* Function Declarations */
static void initialize_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c32_juecefinishi(SFc32_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void c32_update_debugger_state_c32_juecefinishi
  (SFc32_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c32_juecefinishi
  (SFc32_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_st);
static void finalize_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c32_y, const char_T *c32_identifier, real_T c32_b_y[12]);
static void c32_b_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  real_T c32_y[12]);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static real_T c32_c_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_d_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static uint8_T c32_e_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_juecefinishi, const char_T *
  c32_identifier);
static uint8_T c32_f_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void init_dsm_address_info(SFc32_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c32_is_active_c32_juecefinishi = 0U;
}

static void initialize_params_c32_juecefinishi(SFc32_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c32_update_debugger_state_c32_juecefinishi
  (SFc32_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c32_juecefinishi
  (SFc32_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  int32_T c32_i0;
  real_T c32_u[12];
  const mxArray *c32_b_y = NULL;
  uint8_T c32_hoistedGlobal;
  uint8_T c32_b_u;
  const mxArray *c32_c_y = NULL;
  real_T (*c32_d_y)[12];
  c32_d_y = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellmatrix(2, 1), false);
  for (c32_i0 = 0; c32_i0 < 12; c32_i0++) {
    c32_u[c32_i0] = (*c32_d_y)[c32_i0];
  }

  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_hoistedGlobal = chartInstance->c32_is_active_c32_juecefinishi;
  c32_b_u = c32_hoistedGlobal;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c32_y, 1, c32_c_y);
  sf_mex_assign(&c32_st, c32_y, false);
  return c32_st;
}

static void set_sim_state_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_st)
{
  const mxArray *c32_u;
  real_T c32_dv0[12];
  int32_T c32_i1;
  real_T (*c32_y)[12];
  c32_y = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c32_doneDoubleBufferReInit = true;
  c32_u = sf_mex_dup(c32_st);
  c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 0)), "y",
                       c32_dv0);
  for (c32_i1 = 0; c32_i1 < 12; c32_i1++) {
    (*c32_y)[c32_i1] = c32_dv0[c32_i1];
  }

  chartInstance->c32_is_active_c32_juecefinishi = c32_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 1)),
     "is_active_c32_juecefinishi");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_juecefinishi(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c32_i2;
  int32_T c32_i3;
  real_T c32_u1[12];
  int32_T c32_i4;
  real_T c32_u2[3];
  int32_T c32_i5;
  real_T c32_u3[3];
  uint32_T c32_debug_family_var_map[7];
  real_T c32_canshu[12];
  real_T c32_nargin = 3.0;
  real_T c32_nargout = 1.0;
  real_T c32_y[12];
  int32_T c32_i6;
  int32_T c32_i7;
  int32_T c32_i8;
  int32_T c32_i9;
  int32_T c32_i10;
  int32_T c32_i11;
  real_T (*c32_b_y)[12];
  real_T (*c32_b_u3)[3];
  real_T (*c32_b_u2)[3];
  real_T (*c32_b_u1)[12];
  c32_b_u3 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c32_b_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c32_b_y = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c32_b_u1 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, chartInstance->c32_sfEvent);
  for (c32_i2 = 0; c32_i2 < 12; c32_i2++) {
    _SFD_DATA_RANGE_CHECK((*c32_b_u1)[c32_i2], 0U);
  }

  chartInstance->c32_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c32_sfEvent);
  for (c32_i3 = 0; c32_i3 < 12; c32_i3++) {
    c32_u1[c32_i3] = (*c32_b_u1)[c32_i3];
  }

  for (c32_i4 = 0; c32_i4 < 3; c32_i4++) {
    c32_u2[c32_i4] = (*c32_b_u2)[c32_i4];
  }

  for (c32_i5 = 0; c32_i5 < 3; c32_i5++) {
    c32_u3[c32_i5] = (*c32_b_u3)[c32_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c32_debug_family_names,
    c32_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c32_canshu, 0U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargin, 1U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargout, 2U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_u1, 3U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_u2, 4U, c32_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_u3, 5U, c32_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c32_y, 6U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 6);
  for (c32_i6 = 0; c32_i6 < 12; c32_i6++) {
    c32_canshu[c32_i6] = c32_u1[c32_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 7);
  for (c32_i7 = 0; c32_i7 < 12; c32_i7++) {
    c32_y[c32_i7] = c32_u1[c32_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c32_i8 = 0; c32_i8 < 12; c32_i8++) {
    (*c32_b_y)[c32_i8] = c32_y[c32_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c32_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c32_i9 = 0; c32_i9 < 12; c32_i9++) {
    _SFD_DATA_RANGE_CHECK((*c32_b_y)[c32_i9], 1U);
  }

  for (c32_i10 = 0; c32_i10 < 3; c32_i10++) {
    _SFD_DATA_RANGE_CHECK((*c32_b_u2)[c32_i10], 2U);
  }

  for (c32_i11 = 0; c32_i11 < 3; c32_i11++) {
    _SFD_DATA_RANGE_CHECK((*c32_b_u3)[c32_i11], 3U);
  }
}

static void initSimStructsc32_juecefinishi(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber)
{
  (void)c32_machineNumber;
  (void)c32_chartNumber;
  (void)c32_instanceNumber;
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i12;
  real_T c32_b_inData[12];
  int32_T c32_i13;
  real_T c32_u[12];
  const mxArray *c32_y = NULL;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i12 = 0; c32_i12 < 12; c32_i12++) {
    c32_b_inData[c32_i12] = (*(real_T (*)[12])c32_inData)[c32_i12];
  }

  for (c32_i13 = 0; c32_i13 < 12; c32_i13++) {
    c32_u[c32_i13] = c32_b_inData[c32_i13];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static void c32_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c32_y, const char_T *c32_identifier, real_T c32_b_y[12])
{
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_y), &c32_thisId, c32_b_y);
  sf_mex_destroy(&c32_y);
}

static void c32_b_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  real_T c32_y[12])
{
  real_T c32_dv1[12];
  int32_T c32_i14;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_dv1, 1, 0, 0U, 1, 0U, 1, 12);
  for (c32_i14 = 0; c32_i14 < 12; c32_i14++) {
    c32_y[c32_i14] = c32_dv1[c32_i14];
  }

  sf_mex_destroy(&c32_u);
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_y;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_b_y[12];
  int32_T c32_i15;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_y = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_y), &c32_thisId, c32_b_y);
  sf_mex_destroy(&c32_y);
  for (c32_i15 = 0; c32_i15 < 12; c32_i15++) {
    (*(real_T (*)[12])c32_outData)[c32_i15] = c32_b_y[c32_i15];
  }

  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i16;
  real_T c32_b_inData[3];
  int32_T c32_i17;
  real_T c32_u[3];
  const mxArray *c32_y = NULL;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i16 = 0; c32_i16 < 3; c32_i16++) {
    c32_b_inData[c32_i16] = (*(real_T (*)[3])c32_inData)[c32_i16];
  }

  for (c32_i17 = 0; c32_i17 < 3; c32_i17++) {
    c32_u[c32_i17] = c32_b_inData[c32_i17];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static real_T c32_c_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d0;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d0, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_nargout;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_nargout = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_nargout),
    &c32_thisId);
  sf_mex_destroy(&c32_nargout);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

const mxArray *sf_c32_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  sf_mex_assign(&c32_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c32_nameCaptureInfo;
}

static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static int32_T c32_d_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i18;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i18, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i18;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc32_juecefinishiInstanceStruct *)chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static uint8_T c32_e_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_juecefinishi, const char_T *
  c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c32_b_is_active_c32_juecefinishi), &c32_thisId);
  sf_mex_destroy(&c32_b_is_active_c32_juecefinishi);
  return c32_y;
}

static uint8_T c32_f_emlrt_marshallIn(SFc32_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u0;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u0, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void init_dsm_address_info(SFc32_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c32_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(727137302U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3290396100U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4170431530U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4002583374U);
}

mxArray *sf_c32_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bffJZHDIxUTRA2fGfnhrDD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c32_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c32_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c32_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c32_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc32_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           32,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_juecefinishiMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_juecefinishiMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _juecefinishiMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u3");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,88);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)
            c32_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c32_u1)[12];
          real_T (*c32_y)[12];
          real_T (*c32_u2)[3];
          real_T (*c32_u3)[3];
          c32_u3 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c32_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c32_y = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
          c32_u1 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c32_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c32_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c32_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c32_u3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _juecefinishiMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "gedevDeQUlOd3SQL010MNC";
}

static void sf_opaque_initialize_c32_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c32_juecefinishi(void *chartInstanceVar)
{
  enable_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_juecefinishi(void *chartInstanceVar)
{
  disable_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c32_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c32_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c32_juecefinishi
    ((SFc32_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c32_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c32_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c32_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c32_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c32_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c32_juecefinishi(S, st);
}

static void sf_opaque_terminate_c32_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_juecefinishi(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c32_juecefinishi((SFc32_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,32,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,32);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,32,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2839810859U));
  ssSetChecksum1(S,(2851832342U));
  ssSetChecksum2(S,(2494710235U));
  ssSetChecksum3(S,(2403366942U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c32_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_juecefinishi(SimStruct *S)
{
  SFc32_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc32_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc32_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc32_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c32_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c32_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c32_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c32_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c32_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c32_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c32_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c32_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c32_juecefinishi;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c32_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
