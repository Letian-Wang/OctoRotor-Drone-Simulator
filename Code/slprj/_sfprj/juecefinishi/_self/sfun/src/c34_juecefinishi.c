/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c34_juecefinishi.h"
#include "mwmathutil.h"
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
static const char * c34_debug_family_names[11] = { "g", "phi", "theta", "psi",
  "R", "g_b", "nargin", "nargout", "u1", "u2", "y" };

/* Function Declarations */
static void initialize_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c34_juecefinishi(SFc34_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void c34_update_debugger_state_c34_juecefinishi
  (SFc34_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c34_juecefinishi
  (SFc34_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_st);
static void finalize_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void c34_chartstep_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber);
static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c34_y, const char_T *c34_identifier, real_T c34_b_y[3]);
static void c34_b_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[3]);
static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static real_T c34_c_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_d_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[9]);
static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static void c34_info_helper(const mxArray **c34_info);
static const mxArray *c34_emlrt_marshallOut(const char * c34_u);
static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u);
static void c34_inv3x3(SFc34_juecefinishiInstanceStruct *chartInstance, real_T
  c34_x[9], real_T c34_y[9]);
static real_T c34_norm(SFc34_juecefinishiInstanceStruct *chartInstance, real_T
  c34_x[9]);
static void c34_eml_warning(SFc34_juecefinishiInstanceStruct *chartInstance);
static void c34_b_eml_warning(SFc34_juecefinishiInstanceStruct *chartInstance,
  char_T c34_varargin_2[14]);
static void c34_eml_scalar_eg(SFc34_juecefinishiInstanceStruct *chartInstance);
static void c34_eml_xgemm(SFc34_juecefinishiInstanceStruct *chartInstance,
  real_T c34_A[9], real_T c34_B[3], real_T c34_C[3], real_T c34_b_C[3]);
static void c34_e_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_sprintf, const char_T *c34_identifier,
  char_T c34_y[14]);
static void c34_f_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  char_T c34_y[14]);
static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static int32_T c34_g_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static uint8_T c34_h_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_juecefinishi, const char_T *
  c34_identifier);
static uint8_T c34_i_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_eml_xgemm(SFc34_juecefinishiInstanceStruct *chartInstance,
  real_T c34_A[9], real_T c34_B[3], real_T c34_C[3]);
static void init_dsm_address_info(SFc34_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c34_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c34_is_active_c34_juecefinishi = 0U;
}

static void initialize_params_c34_juecefinishi(SFc34_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c34_update_debugger_state_c34_juecefinishi
  (SFc34_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c34_juecefinishi
  (SFc34_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c34_st;
  const mxArray *c34_y = NULL;
  int32_T c34_i0;
  real_T c34_u[3];
  const mxArray *c34_b_y = NULL;
  uint8_T c34_hoistedGlobal;
  uint8_T c34_b_u;
  const mxArray *c34_c_y = NULL;
  real_T (*c34_d_y)[3];
  c34_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c34_st = NULL;
  c34_st = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_createcellmatrix(2, 1), false);
  for (c34_i0 = 0; c34_i0 < 3; c34_i0++) {
    c34_u[c34_i0] = (*c34_d_y)[c34_i0];
  }

  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c34_y, 0, c34_b_y);
  c34_hoistedGlobal = chartInstance->c34_is_active_c34_juecefinishi;
  c34_b_u = c34_hoistedGlobal;
  c34_c_y = NULL;
  sf_mex_assign(&c34_c_y, sf_mex_create("y", &c34_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c34_y, 1, c34_c_y);
  sf_mex_assign(&c34_st, c34_y, false);
  return c34_st;
}

static void set_sim_state_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_st)
{
  const mxArray *c34_u;
  real_T c34_dv0[3];
  int32_T c34_i1;
  real_T (*c34_y)[3];
  c34_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c34_doneDoubleBufferReInit = true;
  c34_u = sf_mex_dup(c34_st);
  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 0)), "y",
                       c34_dv0);
  for (c34_i1 = 0; c34_i1 < 3; c34_i1++) {
    (*c34_y)[c34_i1] = c34_dv0[c34_i1];
  }

  chartInstance->c34_is_active_c34_juecefinishi = c34_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 1)),
     "is_active_c34_juecefinishi");
  sf_mex_destroy(&c34_u);
  c34_update_debugger_state_c34_juecefinishi(chartInstance);
  sf_mex_destroy(&c34_st);
}

static void finalize_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c34_i2;
  int32_T c34_i3;
  int32_T c34_i4;
  real_T (*c34_u2)[3];
  real_T (*c34_y)[3];
  real_T (*c34_u1)[3];
  c34_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c34_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c34_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c34_sfEvent);
  for (c34_i2 = 0; c34_i2 < 3; c34_i2++) {
    _SFD_DATA_RANGE_CHECK((*c34_u1)[c34_i2], 0U);
  }

  chartInstance->c34_sfEvent = CALL_EVENT;
  c34_chartstep_c34_juecefinishi(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c34_i3 = 0; c34_i3 < 3; c34_i3++) {
    _SFD_DATA_RANGE_CHECK((*c34_y)[c34_i3], 1U);
  }

  for (c34_i4 = 0; c34_i4 < 3; c34_i4++) {
    _SFD_DATA_RANGE_CHECK((*c34_u2)[c34_i4], 2U);
  }
}

static void c34_chartstep_c34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c34_i5;
  real_T c34_u1[3];
  int32_T c34_i6;
  real_T c34_u2[3];
  uint32_T c34_debug_family_var_map[11];
  real_T c34_g[3];
  real_T c34_phi;
  real_T c34_theta;
  real_T c34_psi;
  real_T c34_R[9];
  real_T c34_g_b[3];
  real_T c34_nargin = 2.0;
  real_T c34_nargout = 1.0;
  real_T c34_y[3];
  int32_T c34_i7;
  real_T c34_x;
  real_T c34_b_x;
  real_T c34_c_x;
  real_T c34_d_x;
  real_T c34_e_x;
  real_T c34_f_x;
  real_T c34_g_x;
  real_T c34_h_x;
  real_T c34_i_x;
  real_T c34_j_x;
  real_T c34_k_x;
  real_T c34_l_x;
  real_T c34_m_x;
  real_T c34_n_x;
  real_T c34_o_x;
  real_T c34_p_x;
  real_T c34_q_x;
  real_T c34_r_x;
  real_T c34_s_x;
  real_T c34_t_x;
  real_T c34_u_x;
  real_T c34_v_x;
  real_T c34_w_x;
  real_T c34_x_x;
  real_T c34_y_x;
  real_T c34_ab_x;
  real_T c34_bb_x;
  real_T c34_cb_x;
  real_T c34_db_x;
  real_T c34_eb_x;
  real_T c34_fb_x;
  real_T c34_gb_x;
  real_T c34_hb_x;
  real_T c34_ib_x;
  real_T c34_jb_x;
  real_T c34_kb_x;
  real_T c34_lb_x;
  real_T c34_mb_x;
  real_T c34_nb_x;
  real_T c34_ob_x;
  real_T c34_pb_x;
  real_T c34_qb_x;
  real_T c34_rb_x;
  real_T c34_sb_x;
  real_T c34_tb_x;
  real_T c34_ub_x;
  real_T c34_vb_x;
  real_T c34_wb_x;
  real_T c34_xb_x;
  real_T c34_yb_x;
  real_T c34_ac_x;
  real_T c34_bc_x;
  real_T c34_cc_x;
  real_T c34_dc_x;
  real_T c34_ec_x;
  real_T c34_fc_x;
  real_T c34_gc_x;
  real_T c34_hc_x;
  int32_T c34_i8;
  real_T c34_a[9];
  int32_T c34_i9;
  real_T c34_b_a[9];
  real_T c34_c[9];
  int32_T c34_i10;
  real_T c34_c_a[9];
  real_T c34_n1x;
  int32_T c34_i11;
  real_T c34_b_c[9];
  real_T c34_n1xinv;
  real_T c34_rc;
  real_T c34_ic_x;
  boolean_T c34_b;
  real_T c34_jc_x;
  int32_T c34_i12;
  static char_T c34_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c34_u[8];
  const mxArray *c34_b_y = NULL;
  real_T c34_b_u;
  const mxArray *c34_c_y = NULL;
  real_T c34_c_u;
  const mxArray *c34_d_y = NULL;
  real_T c34_d_u;
  const mxArray *c34_e_y = NULL;
  char_T c34_str[14];
  int32_T c34_i13;
  char_T c34_b_str[14];
  int32_T c34_i14;
  real_T c34_b_b[3];
  int32_T c34_i15;
  int32_T c34_i16;
  int32_T c34_i17;
  real_T c34_dv1[9];
  int32_T c34_i18;
  real_T c34_dv2[3];
  int32_T c34_i19;
  real_T c34_dv3[9];
  int32_T c34_i20;
  real_T c34_dv4[3];
  int32_T c34_i21;
  int32_T c34_i22;
  real_T (*c34_f_y)[3];
  real_T (*c34_b_u2)[3];
  real_T (*c34_b_u1)[3];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c34_b_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c34_f_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c34_b_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c34_sfEvent);
  for (c34_i5 = 0; c34_i5 < 3; c34_i5++) {
    c34_u1[c34_i5] = (*c34_b_u1)[c34_i5];
  }

  for (c34_i6 = 0; c34_i6 < 3; c34_i6++) {
    c34_u2[c34_i6] = (*c34_b_u2)[c34_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c34_debug_family_names,
    c34_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_g, 0U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_phi, 1U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_theta, 2U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_psi, 3U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_R, 4U, c34_c_sf_marshallOut,
    c34_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_g_b, 5U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargin, 6U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargout, 7U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_u1, 8U, c34_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_u2, 9U, c34_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_y, 10U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 9);
  for (c34_i7 = 0; c34_i7 < 3; c34_i7++) {
    c34_g[c34_i7] = c34_u1[c34_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 10);
  c34_phi = c34_u2[0];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 11);
  c34_theta = c34_u2[1];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 12);
  c34_psi = c34_u2[2];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 15);
  c34_x = c34_theta;
  c34_b_x = c34_x;
  c34_b_x = muDoubleScalarCos(c34_b_x);
  c34_c_x = c34_psi;
  c34_d_x = c34_c_x;
  c34_d_x = muDoubleScalarCos(c34_d_x);
  c34_e_x = c34_psi;
  c34_f_x = c34_e_x;
  c34_f_x = muDoubleScalarCos(c34_f_x);
  c34_g_x = c34_theta;
  c34_h_x = c34_g_x;
  c34_h_x = muDoubleScalarSin(c34_h_x);
  c34_i_x = c34_phi;
  c34_j_x = c34_i_x;
  c34_j_x = muDoubleScalarSin(c34_j_x);
  c34_k_x = c34_psi;
  c34_l_x = c34_k_x;
  c34_l_x = muDoubleScalarSin(c34_l_x);
  c34_m_x = c34_phi;
  c34_n_x = c34_m_x;
  c34_n_x = muDoubleScalarCos(c34_n_x);
  c34_o_x = c34_psi;
  c34_p_x = c34_o_x;
  c34_p_x = muDoubleScalarCos(c34_p_x);
  c34_q_x = c34_theta;
  c34_r_x = c34_q_x;
  c34_r_x = muDoubleScalarSin(c34_r_x);
  c34_s_x = c34_phi;
  c34_t_x = c34_s_x;
  c34_t_x = muDoubleScalarCos(c34_t_x);
  c34_u_x = c34_psi;
  c34_v_x = c34_u_x;
  c34_v_x = muDoubleScalarSin(c34_v_x);
  c34_w_x = c34_phi;
  c34_x_x = c34_w_x;
  c34_x_x = muDoubleScalarSin(c34_x_x);
  c34_y_x = c34_theta;
  c34_ab_x = c34_y_x;
  c34_ab_x = muDoubleScalarCos(c34_ab_x);
  c34_bb_x = c34_psi;
  c34_cb_x = c34_bb_x;
  c34_cb_x = muDoubleScalarSin(c34_cb_x);
  c34_db_x = c34_psi;
  c34_eb_x = c34_db_x;
  c34_eb_x = muDoubleScalarSin(c34_eb_x);
  c34_fb_x = c34_theta;
  c34_gb_x = c34_fb_x;
  c34_gb_x = muDoubleScalarSin(c34_gb_x);
  c34_hb_x = c34_phi;
  c34_ib_x = c34_hb_x;
  c34_ib_x = muDoubleScalarSin(c34_ib_x);
  c34_jb_x = c34_psi;
  c34_kb_x = c34_jb_x;
  c34_kb_x = muDoubleScalarCos(c34_kb_x);
  c34_lb_x = c34_phi;
  c34_mb_x = c34_lb_x;
  c34_mb_x = muDoubleScalarCos(c34_mb_x);
  c34_nb_x = c34_psi;
  c34_ob_x = c34_nb_x;
  c34_ob_x = muDoubleScalarSin(c34_ob_x);
  c34_pb_x = c34_theta;
  c34_qb_x = c34_pb_x;
  c34_qb_x = muDoubleScalarSin(c34_qb_x);
  c34_rb_x = c34_phi;
  c34_sb_x = c34_rb_x;
  c34_sb_x = muDoubleScalarCos(c34_sb_x);
  c34_tb_x = c34_psi;
  c34_ub_x = c34_tb_x;
  c34_ub_x = muDoubleScalarCos(c34_ub_x);
  c34_vb_x = c34_phi;
  c34_wb_x = c34_vb_x;
  c34_wb_x = muDoubleScalarSin(c34_wb_x);
  c34_xb_x = c34_theta;
  c34_yb_x = c34_xb_x;
  c34_yb_x = muDoubleScalarSin(c34_yb_x);
  c34_ac_x = c34_phi;
  c34_bc_x = c34_ac_x;
  c34_bc_x = muDoubleScalarSin(c34_bc_x);
  c34_cc_x = c34_theta;
  c34_dc_x = c34_cc_x;
  c34_dc_x = muDoubleScalarCos(c34_dc_x);
  c34_ec_x = c34_phi;
  c34_fc_x = c34_ec_x;
  c34_fc_x = muDoubleScalarCos(c34_fc_x);
  c34_gc_x = c34_theta;
  c34_hc_x = c34_gc_x;
  c34_hc_x = muDoubleScalarCos(c34_hc_x);
  c34_R[0] = c34_b_x * c34_d_x;
  c34_R[3] = c34_f_x * c34_h_x * c34_j_x - c34_l_x * c34_n_x;
  c34_R[6] = c34_p_x * c34_r_x * c34_t_x + c34_v_x * c34_x_x;
  c34_R[1] = c34_ab_x * c34_cb_x;
  c34_R[4] = c34_eb_x * c34_gb_x * c34_ib_x + c34_kb_x * c34_mb_x;
  c34_R[7] = c34_ob_x * c34_qb_x * c34_sb_x - c34_ub_x * c34_wb_x;
  c34_R[2] = -c34_yb_x;
  c34_R[5] = c34_bc_x * c34_dc_x;
  c34_R[8] = c34_fc_x * c34_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 19);
  for (c34_i8 = 0; c34_i8 < 9; c34_i8++) {
    c34_a[c34_i8] = c34_R[c34_i8];
  }

  for (c34_i9 = 0; c34_i9 < 9; c34_i9++) {
    c34_b_a[c34_i9] = c34_a[c34_i9];
  }

  c34_inv3x3(chartInstance, c34_b_a, c34_c);
  for (c34_i10 = 0; c34_i10 < 9; c34_i10++) {
    c34_c_a[c34_i10] = c34_a[c34_i10];
  }

  c34_n1x = c34_norm(chartInstance, c34_c_a);
  for (c34_i11 = 0; c34_i11 < 9; c34_i11++) {
    c34_b_c[c34_i11] = c34_c[c34_i11];
  }

  c34_n1xinv = c34_norm(chartInstance, c34_b_c);
  c34_rc = 1.0 / (c34_n1x * c34_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c34_n1x == 0.0) {
    guard2 = true;
  } else if (c34_n1xinv == 0.0) {
    guard2 = true;
  } else if (c34_rc == 0.0) {
    guard1 = true;
  } else {
    c34_ic_x = c34_rc;
    c34_b = muDoubleScalarIsNaN(c34_ic_x);
    guard3 = false;
    if (c34_b) {
      guard3 = true;
    } else {
      if (c34_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c34_jc_x = c34_rc;
      for (c34_i12 = 0; c34_i12 < 8; c34_i12++) {
        c34_u[c34_i12] = c34_cv0[c34_i12];
      }

      c34_b_y = NULL;
      sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c34_b_u = 14.0;
      c34_c_y = NULL;
      sf_mex_assign(&c34_c_y, sf_mex_create("y", &c34_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c34_c_u = 6.0;
      c34_d_y = NULL;
      sf_mex_assign(&c34_d_y, sf_mex_create("y", &c34_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c34_d_u = c34_jc_x;
      c34_e_y = NULL;
      sf_mex_assign(&c34_e_y, sf_mex_create("y", &c34_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c34_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c34_b_y, 14,
          c34_c_y, 14, c34_d_y), 14, c34_e_y), "sprintf", c34_str);
      for (c34_i13 = 0; c34_i13 < 14; c34_i13++) {
        c34_b_str[c34_i13] = c34_str[c34_i13];
      }

      c34_b_eml_warning(chartInstance, c34_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c34_eml_warning(chartInstance);
  }

  for (c34_i14 = 0; c34_i14 < 3; c34_i14++) {
    c34_b_b[c34_i14] = c34_g[c34_i14];
  }

  c34_eml_scalar_eg(chartInstance);
  c34_eml_scalar_eg(chartInstance);
  for (c34_i15 = 0; c34_i15 < 3; c34_i15++) {
    c34_g_b[c34_i15] = 0.0;
  }

  for (c34_i16 = 0; c34_i16 < 3; c34_i16++) {
    c34_g_b[c34_i16] = 0.0;
  }

  for (c34_i17 = 0; c34_i17 < 9; c34_i17++) {
    c34_dv1[c34_i17] = c34_c[c34_i17];
  }

  for (c34_i18 = 0; c34_i18 < 3; c34_i18++) {
    c34_dv2[c34_i18] = c34_b_b[c34_i18];
  }

  for (c34_i19 = 0; c34_i19 < 9; c34_i19++) {
    c34_dv3[c34_i19] = c34_dv1[c34_i19];
  }

  for (c34_i20 = 0; c34_i20 < 3; c34_i20++) {
    c34_dv4[c34_i20] = c34_dv2[c34_i20];
  }

  c34_b_eml_xgemm(chartInstance, c34_dv3, c34_dv4, c34_g_b);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 20);
  for (c34_i21 = 0; c34_i21 < 3; c34_i21++) {
    c34_y[c34_i21] = c34_g_b[c34_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  for (c34_i22 = 0; c34_i22 < 3; c34_i22++) {
    (*c34_f_y)[c34_i22] = c34_y[c34_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c34_sfEvent);
}

static void initSimStructsc34_juecefinishi(SFc34_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber)
{
  (void)c34_machineNumber;
  (void)c34_chartNumber;
  (void)c34_instanceNumber;
}

static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i23;
  real_T c34_b_inData[3];
  int32_T c34_i24;
  real_T c34_u[3];
  const mxArray *c34_y = NULL;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  for (c34_i23 = 0; c34_i23 < 3; c34_i23++) {
    c34_b_inData[c34_i23] = (*(real_T (*)[3])c34_inData)[c34_i23];
  }

  for (c34_i24 = 0; c34_i24 < 3; c34_i24++) {
    c34_u[c34_i24] = c34_b_inData[c34_i24];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static void c34_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c34_y, const char_T *c34_identifier, real_T c34_b_y[3])
{
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_y), &c34_thisId, c34_b_y);
  sf_mex_destroy(&c34_y);
}

static void c34_b_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[3])
{
  real_T c34_dv5[3];
  int32_T c34_i25;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c34_i25 = 0; c34_i25 < 3; c34_i25++) {
    c34_y[c34_i25] = c34_dv5[c34_i25];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_y;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_b_y[3];
  int32_T c34_i26;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_y = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_y), &c34_thisId, c34_b_y);
  sf_mex_destroy(&c34_y);
  for (c34_i26 = 0; c34_i26 < 3; c34_i26++) {
    (*(real_T (*)[3])c34_outData)[c34_i26] = c34_b_y[c34_i26];
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  real_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(real_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static real_T c34_c_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  real_T c34_y;
  real_T c34_d0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_d0, 1, 0, 0U, 0, 0U, 0);
  c34_y = c34_d0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_nargout;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_nargout = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_nargout),
    &c34_thisId);
  sf_mex_destroy(&c34_nargout);
  *(real_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i27;
  int32_T c34_i28;
  int32_T c34_i29;
  real_T c34_b_inData[9];
  int32_T c34_i30;
  int32_T c34_i31;
  int32_T c34_i32;
  real_T c34_u[9];
  const mxArray *c34_y = NULL;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_i27 = 0;
  for (c34_i28 = 0; c34_i28 < 3; c34_i28++) {
    for (c34_i29 = 0; c34_i29 < 3; c34_i29++) {
      c34_b_inData[c34_i29 + c34_i27] = (*(real_T (*)[9])c34_inData)[c34_i29 +
        c34_i27];
    }

    c34_i27 += 3;
  }

  c34_i30 = 0;
  for (c34_i31 = 0; c34_i31 < 3; c34_i31++) {
    for (c34_i32 = 0; c34_i32 < 3; c34_i32++) {
      c34_u[c34_i32 + c34_i30] = c34_b_inData[c34_i32 + c34_i30];
    }

    c34_i30 += 3;
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static void c34_d_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[9])
{
  real_T c34_dv6[9];
  int32_T c34_i33;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_dv6, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c34_i33 = 0; c34_i33 < 9; c34_i33++) {
    c34_y[c34_i33] = c34_dv6[c34_i33];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_R;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y[9];
  int32_T c34_i34;
  int32_T c34_i35;
  int32_T c34_i36;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_R = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_R), &c34_thisId, c34_y);
  sf_mex_destroy(&c34_R);
  c34_i34 = 0;
  for (c34_i35 = 0; c34_i35 < 3; c34_i35++) {
    for (c34_i36 = 0; c34_i36 < 3; c34_i36++) {
      (*(real_T (*)[9])c34_outData)[c34_i36 + c34_i34] = c34_y[c34_i36 + c34_i34];
    }

    c34_i34 += 3;
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

const mxArray *sf_c34_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c34_nameCaptureInfo = NULL;
  c34_nameCaptureInfo = NULL;
  sf_mex_assign(&c34_nameCaptureInfo, sf_mex_createstruct("structure", 2, 46, 1),
                false);
  c34_info_helper(&c34_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c34_nameCaptureInfo);
  return c34_nameCaptureInfo;
}

static void c34_info_helper(const mxArray **c34_info)
{
  const mxArray *c34_rhs0 = NULL;
  const mxArray *c34_lhs0 = NULL;
  const mxArray *c34_rhs1 = NULL;
  const mxArray *c34_lhs1 = NULL;
  const mxArray *c34_rhs2 = NULL;
  const mxArray *c34_lhs2 = NULL;
  const mxArray *c34_rhs3 = NULL;
  const mxArray *c34_lhs3 = NULL;
  const mxArray *c34_rhs4 = NULL;
  const mxArray *c34_lhs4 = NULL;
  const mxArray *c34_rhs5 = NULL;
  const mxArray *c34_lhs5 = NULL;
  const mxArray *c34_rhs6 = NULL;
  const mxArray *c34_lhs6 = NULL;
  const mxArray *c34_rhs7 = NULL;
  const mxArray *c34_lhs7 = NULL;
  const mxArray *c34_rhs8 = NULL;
  const mxArray *c34_lhs8 = NULL;
  const mxArray *c34_rhs9 = NULL;
  const mxArray *c34_lhs9 = NULL;
  const mxArray *c34_rhs10 = NULL;
  const mxArray *c34_lhs10 = NULL;
  const mxArray *c34_rhs11 = NULL;
  const mxArray *c34_lhs11 = NULL;
  const mxArray *c34_rhs12 = NULL;
  const mxArray *c34_lhs12 = NULL;
  const mxArray *c34_rhs13 = NULL;
  const mxArray *c34_lhs13 = NULL;
  const mxArray *c34_rhs14 = NULL;
  const mxArray *c34_lhs14 = NULL;
  const mxArray *c34_rhs15 = NULL;
  const mxArray *c34_lhs15 = NULL;
  const mxArray *c34_rhs16 = NULL;
  const mxArray *c34_lhs16 = NULL;
  const mxArray *c34_rhs17 = NULL;
  const mxArray *c34_lhs17 = NULL;
  const mxArray *c34_rhs18 = NULL;
  const mxArray *c34_lhs18 = NULL;
  const mxArray *c34_rhs19 = NULL;
  const mxArray *c34_lhs19 = NULL;
  const mxArray *c34_rhs20 = NULL;
  const mxArray *c34_lhs20 = NULL;
  const mxArray *c34_rhs21 = NULL;
  const mxArray *c34_lhs21 = NULL;
  const mxArray *c34_rhs22 = NULL;
  const mxArray *c34_lhs22 = NULL;
  const mxArray *c34_rhs23 = NULL;
  const mxArray *c34_lhs23 = NULL;
  const mxArray *c34_rhs24 = NULL;
  const mxArray *c34_lhs24 = NULL;
  const mxArray *c34_rhs25 = NULL;
  const mxArray *c34_lhs25 = NULL;
  const mxArray *c34_rhs26 = NULL;
  const mxArray *c34_lhs26 = NULL;
  const mxArray *c34_rhs27 = NULL;
  const mxArray *c34_lhs27 = NULL;
  const mxArray *c34_rhs28 = NULL;
  const mxArray *c34_lhs28 = NULL;
  const mxArray *c34_rhs29 = NULL;
  const mxArray *c34_lhs29 = NULL;
  const mxArray *c34_rhs30 = NULL;
  const mxArray *c34_lhs30 = NULL;
  const mxArray *c34_rhs31 = NULL;
  const mxArray *c34_lhs31 = NULL;
  const mxArray *c34_rhs32 = NULL;
  const mxArray *c34_lhs32 = NULL;
  const mxArray *c34_rhs33 = NULL;
  const mxArray *c34_lhs33 = NULL;
  const mxArray *c34_rhs34 = NULL;
  const mxArray *c34_lhs34 = NULL;
  const mxArray *c34_rhs35 = NULL;
  const mxArray *c34_lhs35 = NULL;
  const mxArray *c34_rhs36 = NULL;
  const mxArray *c34_lhs36 = NULL;
  const mxArray *c34_rhs37 = NULL;
  const mxArray *c34_lhs37 = NULL;
  const mxArray *c34_rhs38 = NULL;
  const mxArray *c34_lhs38 = NULL;
  const mxArray *c34_rhs39 = NULL;
  const mxArray *c34_lhs39 = NULL;
  const mxArray *c34_rhs40 = NULL;
  const mxArray *c34_lhs40 = NULL;
  const mxArray *c34_rhs41 = NULL;
  const mxArray *c34_lhs41 = NULL;
  const mxArray *c34_rhs42 = NULL;
  const mxArray *c34_lhs42 = NULL;
  const mxArray *c34_rhs43 = NULL;
  const mxArray *c34_lhs43 = NULL;
  const mxArray *c34_rhs44 = NULL;
  const mxArray *c34_lhs44 = NULL;
  const mxArray *c34_rhs45 = NULL;
  const mxArray *c34_lhs45 = NULL;
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1343837572U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c34_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825922U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c34_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c34_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825936U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c34_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("mpower"), "name", "name", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717478U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c34_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c34_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("ismatrix"), "name", "name",
                  6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1331308458U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c34_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c34_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c34_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c34_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("inv"), "name", "name", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1305325200U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c34_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c34_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("abs"), "name", "name", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c34_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c34_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c34_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_div"), "name", "name",
                  15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c34_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c34_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c34_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c34_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("norm"), "name", "name", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717468U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c34_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c34_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("abs"), "name", "name", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c34_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 22);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c34_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c34_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 24);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 24);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825976U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c34_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c34_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 26);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_warning"), "name",
                  "name", 26);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286826002U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c34_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 27);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("isnan"), "name", "name", 27);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c34_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 28);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eps"), "name", "name", 28);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c34_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c34_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_eps"), "name", "name",
                  30);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c34_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 31);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c34_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 32);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_flt2str"), "name",
                  "name", 32);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1360285950U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c34_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "name", "name", 33);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1319737168U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c34_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 34);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1383880894U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c34_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 35);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c34_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 36);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c34_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c34_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  38);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375987890U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c34_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 39);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c34_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 40);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c34_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 41);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 41);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c34_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 42);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 42);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c34_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 43);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 43);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c34_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 44);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 44);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c34_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 45);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c34_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs45), "lhs", "lhs",
                  45);
  sf_mex_destroy(&c34_rhs0);
  sf_mex_destroy(&c34_lhs0);
  sf_mex_destroy(&c34_rhs1);
  sf_mex_destroy(&c34_lhs1);
  sf_mex_destroy(&c34_rhs2);
  sf_mex_destroy(&c34_lhs2);
  sf_mex_destroy(&c34_rhs3);
  sf_mex_destroy(&c34_lhs3);
  sf_mex_destroy(&c34_rhs4);
  sf_mex_destroy(&c34_lhs4);
  sf_mex_destroy(&c34_rhs5);
  sf_mex_destroy(&c34_lhs5);
  sf_mex_destroy(&c34_rhs6);
  sf_mex_destroy(&c34_lhs6);
  sf_mex_destroy(&c34_rhs7);
  sf_mex_destroy(&c34_lhs7);
  sf_mex_destroy(&c34_rhs8);
  sf_mex_destroy(&c34_lhs8);
  sf_mex_destroy(&c34_rhs9);
  sf_mex_destroy(&c34_lhs9);
  sf_mex_destroy(&c34_rhs10);
  sf_mex_destroy(&c34_lhs10);
  sf_mex_destroy(&c34_rhs11);
  sf_mex_destroy(&c34_lhs11);
  sf_mex_destroy(&c34_rhs12);
  sf_mex_destroy(&c34_lhs12);
  sf_mex_destroy(&c34_rhs13);
  sf_mex_destroy(&c34_lhs13);
  sf_mex_destroy(&c34_rhs14);
  sf_mex_destroy(&c34_lhs14);
  sf_mex_destroy(&c34_rhs15);
  sf_mex_destroy(&c34_lhs15);
  sf_mex_destroy(&c34_rhs16);
  sf_mex_destroy(&c34_lhs16);
  sf_mex_destroy(&c34_rhs17);
  sf_mex_destroy(&c34_lhs17);
  sf_mex_destroy(&c34_rhs18);
  sf_mex_destroy(&c34_lhs18);
  sf_mex_destroy(&c34_rhs19);
  sf_mex_destroy(&c34_lhs19);
  sf_mex_destroy(&c34_rhs20);
  sf_mex_destroy(&c34_lhs20);
  sf_mex_destroy(&c34_rhs21);
  sf_mex_destroy(&c34_lhs21);
  sf_mex_destroy(&c34_rhs22);
  sf_mex_destroy(&c34_lhs22);
  sf_mex_destroy(&c34_rhs23);
  sf_mex_destroy(&c34_lhs23);
  sf_mex_destroy(&c34_rhs24);
  sf_mex_destroy(&c34_lhs24);
  sf_mex_destroy(&c34_rhs25);
  sf_mex_destroy(&c34_lhs25);
  sf_mex_destroy(&c34_rhs26);
  sf_mex_destroy(&c34_lhs26);
  sf_mex_destroy(&c34_rhs27);
  sf_mex_destroy(&c34_lhs27);
  sf_mex_destroy(&c34_rhs28);
  sf_mex_destroy(&c34_lhs28);
  sf_mex_destroy(&c34_rhs29);
  sf_mex_destroy(&c34_lhs29);
  sf_mex_destroy(&c34_rhs30);
  sf_mex_destroy(&c34_lhs30);
  sf_mex_destroy(&c34_rhs31);
  sf_mex_destroy(&c34_lhs31);
  sf_mex_destroy(&c34_rhs32);
  sf_mex_destroy(&c34_lhs32);
  sf_mex_destroy(&c34_rhs33);
  sf_mex_destroy(&c34_lhs33);
  sf_mex_destroy(&c34_rhs34);
  sf_mex_destroy(&c34_lhs34);
  sf_mex_destroy(&c34_rhs35);
  sf_mex_destroy(&c34_lhs35);
  sf_mex_destroy(&c34_rhs36);
  sf_mex_destroy(&c34_lhs36);
  sf_mex_destroy(&c34_rhs37);
  sf_mex_destroy(&c34_lhs37);
  sf_mex_destroy(&c34_rhs38);
  sf_mex_destroy(&c34_lhs38);
  sf_mex_destroy(&c34_rhs39);
  sf_mex_destroy(&c34_lhs39);
  sf_mex_destroy(&c34_rhs40);
  sf_mex_destroy(&c34_lhs40);
  sf_mex_destroy(&c34_rhs41);
  sf_mex_destroy(&c34_lhs41);
  sf_mex_destroy(&c34_rhs42);
  sf_mex_destroy(&c34_lhs42);
  sf_mex_destroy(&c34_rhs43);
  sf_mex_destroy(&c34_lhs43);
  sf_mex_destroy(&c34_rhs44);
  sf_mex_destroy(&c34_lhs44);
  sf_mex_destroy(&c34_rhs45);
  sf_mex_destroy(&c34_lhs45);
}

static const mxArray *c34_emlrt_marshallOut(const char * c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c34_u)), false);
  return c34_y;
}

static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 7, 0U, 0U, 0U, 0), false);
  return c34_y;
}

static void c34_inv3x3(SFc34_juecefinishiInstanceStruct *chartInstance, real_T
  c34_x[9], real_T c34_y[9])
{
  int32_T c34_p1;
  int32_T c34_p2;
  int32_T c34_p3;
  real_T c34_b_x;
  real_T c34_c_x;
  real_T c34_absx11;
  real_T c34_d_x;
  real_T c34_e_x;
  real_T c34_absx21;
  real_T c34_f_x;
  real_T c34_g_x;
  real_T c34_absx31;
  real_T c34_t1;
  real_T c34_h_x;
  real_T c34_b_y;
  real_T c34_i_x;
  real_T c34_c_y;
  real_T c34_z;
  real_T c34_j_x;
  real_T c34_d_y;
  real_T c34_k_x;
  real_T c34_e_y;
  real_T c34_b_z;
  real_T c34_l_x;
  real_T c34_m_x;
  real_T c34_f_y;
  real_T c34_n_x;
  real_T c34_o_x;
  real_T c34_g_y;
  int32_T c34_itmp;
  real_T c34_p_x;
  real_T c34_h_y;
  real_T c34_q_x;
  real_T c34_i_y;
  real_T c34_c_z;
  real_T c34_r_x;
  real_T c34_j_y;
  real_T c34_s_x;
  real_T c34_k_y;
  real_T c34_t3;
  real_T c34_t_x;
  real_T c34_l_y;
  real_T c34_u_x;
  real_T c34_m_y;
  real_T c34_t2;
  int32_T c34_a;
  int32_T c34_b_a;
  int32_T c34_c;
  real_T c34_v_x;
  real_T c34_n_y;
  real_T c34_w_x;
  real_T c34_o_y;
  real_T c34_d_z;
  int32_T c34_c_a;
  int32_T c34_d_a;
  int32_T c34_b_c;
  int32_T c34_e_a;
  int32_T c34_f_a;
  int32_T c34_c_c;
  real_T c34_x_x;
  real_T c34_p_y;
  real_T c34_y_x;
  real_T c34_q_y;
  real_T c34_ab_x;
  real_T c34_r_y;
  real_T c34_bb_x;
  real_T c34_s_y;
  int32_T c34_g_a;
  int32_T c34_h_a;
  int32_T c34_d_c;
  real_T c34_cb_x;
  real_T c34_t_y;
  real_T c34_db_x;
  real_T c34_u_y;
  real_T c34_e_z;
  int32_T c34_i_a;
  int32_T c34_j_a;
  int32_T c34_e_c;
  int32_T c34_k_a;
  int32_T c34_l_a;
  int32_T c34_f_c;
  real_T c34_v_y;
  real_T c34_w_y;
  real_T c34_eb_x;
  real_T c34_x_y;
  real_T c34_fb_x;
  real_T c34_y_y;
  int32_T c34_m_a;
  int32_T c34_n_a;
  int32_T c34_g_c;
  real_T c34_gb_x;
  real_T c34_ab_y;
  real_T c34_hb_x;
  real_T c34_bb_y;
  real_T c34_f_z;
  int32_T c34_o_a;
  int32_T c34_p_a;
  int32_T c34_h_c;
  int32_T c34_q_a;
  int32_T c34_r_a;
  int32_T c34_i_c;
  boolean_T guard1 = false;
  (void)chartInstance;
  c34_p1 = 0;
  c34_p2 = 3;
  c34_p3 = 6;
  c34_b_x = c34_x[0];
  c34_c_x = c34_b_x;
  c34_absx11 = muDoubleScalarAbs(c34_c_x);
  c34_d_x = c34_x[1];
  c34_e_x = c34_d_x;
  c34_absx21 = muDoubleScalarAbs(c34_e_x);
  c34_f_x = c34_x[2];
  c34_g_x = c34_f_x;
  c34_absx31 = muDoubleScalarAbs(c34_g_x);
  guard1 = false;
  if (c34_absx21 > c34_absx11) {
    if (c34_absx21 > c34_absx31) {
      c34_p1 = 3;
      c34_p2 = 0;
      c34_t1 = c34_x[0];
      c34_x[0] = c34_x[1];
      c34_x[1] = c34_t1;
      c34_t1 = c34_x[3];
      c34_x[3] = c34_x[4];
      c34_x[4] = c34_t1;
      c34_t1 = c34_x[6];
      c34_x[6] = c34_x[7];
      c34_x[7] = c34_t1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    if (c34_absx31 > c34_absx11) {
      c34_p1 = 6;
      c34_p3 = 0;
      c34_t1 = c34_x[0];
      c34_x[0] = c34_x[2];
      c34_x[2] = c34_t1;
      c34_t1 = c34_x[3];
      c34_x[3] = c34_x[5];
      c34_x[5] = c34_t1;
      c34_t1 = c34_x[6];
      c34_x[6] = c34_x[8];
      c34_x[8] = c34_t1;
    }
  }

  c34_h_x = c34_x[1];
  c34_b_y = c34_x[0];
  c34_i_x = c34_h_x;
  c34_c_y = c34_b_y;
  c34_z = c34_i_x / c34_c_y;
  c34_x[1] = c34_z;
  c34_j_x = c34_x[2];
  c34_d_y = c34_x[0];
  c34_k_x = c34_j_x;
  c34_e_y = c34_d_y;
  c34_b_z = c34_k_x / c34_e_y;
  c34_x[2] = c34_b_z;
  c34_x[4] -= c34_x[1] * c34_x[3];
  c34_x[5] -= c34_x[2] * c34_x[3];
  c34_x[7] -= c34_x[1] * c34_x[6];
  c34_x[8] -= c34_x[2] * c34_x[6];
  c34_l_x = c34_x[5];
  c34_m_x = c34_l_x;
  c34_f_y = muDoubleScalarAbs(c34_m_x);
  c34_n_x = c34_x[4];
  c34_o_x = c34_n_x;
  c34_g_y = muDoubleScalarAbs(c34_o_x);
  if (c34_f_y > c34_g_y) {
    c34_itmp = c34_p2;
    c34_p2 = c34_p3;
    c34_p3 = c34_itmp;
    c34_t1 = c34_x[1];
    c34_x[1] = c34_x[2];
    c34_x[2] = c34_t1;
    c34_t1 = c34_x[4];
    c34_x[4] = c34_x[5];
    c34_x[5] = c34_t1;
    c34_t1 = c34_x[7];
    c34_x[7] = c34_x[8];
    c34_x[8] = c34_t1;
  }

  c34_p_x = c34_x[5];
  c34_h_y = c34_x[4];
  c34_q_x = c34_p_x;
  c34_i_y = c34_h_y;
  c34_c_z = c34_q_x / c34_i_y;
  c34_x[5] = c34_c_z;
  c34_x[8] -= c34_x[5] * c34_x[7];
  c34_r_x = c34_x[5] * c34_x[1] - c34_x[2];
  c34_j_y = c34_x[8];
  c34_s_x = c34_r_x;
  c34_k_y = c34_j_y;
  c34_t3 = c34_s_x / c34_k_y;
  c34_t_x = -(c34_x[1] + c34_x[7] * c34_t3);
  c34_l_y = c34_x[4];
  c34_u_x = c34_t_x;
  c34_m_y = c34_l_y;
  c34_t2 = c34_u_x / c34_m_y;
  c34_a = c34_p1;
  c34_b_a = c34_a + 1;
  c34_c = c34_b_a;
  c34_v_x = (1.0 - c34_x[3] * c34_t2) - c34_x[6] * c34_t3;
  c34_n_y = c34_x[0];
  c34_w_x = c34_v_x;
  c34_o_y = c34_n_y;
  c34_d_z = c34_w_x / c34_o_y;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_c), 1, 9, 1, 0) - 1] = c34_d_z;
  c34_c_a = c34_p1;
  c34_d_a = c34_c_a + 2;
  c34_b_c = c34_d_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_b_c), 1, 9, 1, 0) - 1] = c34_t2;
  c34_e_a = c34_p1;
  c34_f_a = c34_e_a + 3;
  c34_c_c = c34_f_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_c_c), 1, 9, 1, 0) - 1] = c34_t3;
  c34_x_x = -c34_x[5];
  c34_p_y = c34_x[8];
  c34_y_x = c34_x_x;
  c34_q_y = c34_p_y;
  c34_t3 = c34_y_x / c34_q_y;
  c34_ab_x = 1.0 - c34_x[7] * c34_t3;
  c34_r_y = c34_x[4];
  c34_bb_x = c34_ab_x;
  c34_s_y = c34_r_y;
  c34_t2 = c34_bb_x / c34_s_y;
  c34_g_a = c34_p2;
  c34_h_a = c34_g_a + 1;
  c34_d_c = c34_h_a;
  c34_cb_x = -(c34_x[3] * c34_t2 + c34_x[6] * c34_t3);
  c34_t_y = c34_x[0];
  c34_db_x = c34_cb_x;
  c34_u_y = c34_t_y;
  c34_e_z = c34_db_x / c34_u_y;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_d_c), 1, 9, 1, 0) - 1] = c34_e_z;
  c34_i_a = c34_p2;
  c34_j_a = c34_i_a + 2;
  c34_e_c = c34_j_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_e_c), 1, 9, 1, 0) - 1] = c34_t2;
  c34_k_a = c34_p2;
  c34_l_a = c34_k_a + 3;
  c34_f_c = c34_l_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_f_c), 1, 9, 1, 0) - 1] = c34_t3;
  c34_v_y = c34_x[8];
  c34_w_y = c34_v_y;
  c34_t3 = 1.0 / c34_w_y;
  c34_eb_x = -c34_x[7] * c34_t3;
  c34_x_y = c34_x[4];
  c34_fb_x = c34_eb_x;
  c34_y_y = c34_x_y;
  c34_t2 = c34_fb_x / c34_y_y;
  c34_m_a = c34_p3;
  c34_n_a = c34_m_a + 1;
  c34_g_c = c34_n_a;
  c34_gb_x = -(c34_x[3] * c34_t2 + c34_x[6] * c34_t3);
  c34_ab_y = c34_x[0];
  c34_hb_x = c34_gb_x;
  c34_bb_y = c34_ab_y;
  c34_f_z = c34_hb_x / c34_bb_y;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_g_c), 1, 9, 1, 0) - 1] = c34_f_z;
  c34_o_a = c34_p3;
  c34_p_a = c34_o_a + 2;
  c34_h_c = c34_p_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_h_c), 1, 9, 1, 0) - 1] = c34_t2;
  c34_q_a = c34_p3;
  c34_r_a = c34_q_a + 3;
  c34_i_c = c34_r_a;
  c34_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c34_i_c), 1, 9, 1, 0) - 1] = c34_t3;
}

static real_T c34_norm(SFc34_juecefinishiInstanceStruct *chartInstance, real_T
  c34_x[9])
{
  real_T c34_y;
  int32_T c34_j;
  real_T c34_b_j;
  real_T c34_s;
  int32_T c34_i;
  real_T c34_b_i;
  real_T c34_b_x;
  real_T c34_c_x;
  real_T c34_b_y;
  real_T c34_d_x;
  boolean_T c34_b;
  boolean_T exitg1;
  (void)chartInstance;
  c34_y = 0.0;
  c34_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c34_j < 3)) {
    c34_b_j = 1.0 + (real_T)c34_j;
    c34_s = 0.0;
    for (c34_i = 0; c34_i < 3; c34_i++) {
      c34_b_i = 1.0 + (real_T)c34_i;
      c34_b_x = c34_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c34_b_i), 1, 3, 1, 0) + 3 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c34_b_j), 1, 3, 2, 0) - 1)) - 1];
      c34_c_x = c34_b_x;
      c34_b_y = muDoubleScalarAbs(c34_c_x);
      c34_s += c34_b_y;
    }

    c34_d_x = c34_s;
    c34_b = muDoubleScalarIsNaN(c34_d_x);
    if (c34_b) {
      c34_y = rtNaN;
      exitg1 = true;
    } else {
      if (c34_s > c34_y) {
        c34_y = c34_s;
      }

      c34_j++;
    }
  }

  return c34_y;
}

static void c34_eml_warning(SFc34_juecefinishiInstanceStruct *chartInstance)
{
  int32_T c34_i37;
  static char_T c34_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c34_u[27];
  const mxArray *c34_y = NULL;
  (void)chartInstance;
  for (c34_i37 = 0; c34_i37 < 27; c34_i37++) {
    c34_u[c34_i37] = c34_varargin_1[c34_i37];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c34_y));
}

static void c34_b_eml_warning(SFc34_juecefinishiInstanceStruct *chartInstance,
  char_T c34_varargin_2[14])
{
  int32_T c34_i38;
  static char_T c34_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c34_u[33];
  const mxArray *c34_y = NULL;
  int32_T c34_i39;
  char_T c34_b_u[14];
  const mxArray *c34_b_y = NULL;
  (void)chartInstance;
  for (c34_i38 = 0; c34_i38 < 33; c34_i38++) {
    c34_u[c34_i38] = c34_varargin_1[c34_i38];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  for (c34_i39 = 0; c34_i39 < 14; c34_i39++) {
    c34_b_u[c34_i39] = c34_varargin_2[c34_i39];
  }

  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c34_y, 14, c34_b_y));
}

static void c34_eml_scalar_eg(SFc34_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c34_eml_xgemm(SFc34_juecefinishiInstanceStruct *chartInstance,
  real_T c34_A[9], real_T c34_B[3], real_T c34_C[3], real_T c34_b_C[3])
{
  int32_T c34_i40;
  int32_T c34_i41;
  real_T c34_b_A[9];
  int32_T c34_i42;
  real_T c34_b_B[3];
  for (c34_i40 = 0; c34_i40 < 3; c34_i40++) {
    c34_b_C[c34_i40] = c34_C[c34_i40];
  }

  for (c34_i41 = 0; c34_i41 < 9; c34_i41++) {
    c34_b_A[c34_i41] = c34_A[c34_i41];
  }

  for (c34_i42 = 0; c34_i42 < 3; c34_i42++) {
    c34_b_B[c34_i42] = c34_B[c34_i42];
  }

  c34_b_eml_xgemm(chartInstance, c34_b_A, c34_b_B, c34_b_C);
}

static void c34_e_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_sprintf, const char_T *c34_identifier,
  char_T c34_y[14])
{
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_sprintf), &c34_thisId,
    c34_y);
  sf_mex_destroy(&c34_sprintf);
}

static void c34_f_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  char_T c34_y[14])
{
  char_T c34_cv1[14];
  int32_T c34_i43;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c34_i43 = 0; c34_i43 < 14; c34_i43++) {
    c34_y[c34_i43] = c34_cv1[c34_i43];
  }

  sf_mex_destroy(&c34_u);
}

static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(int32_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static int32_T c34_g_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  int32_T c34_y;
  int32_T c34_i44;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_i44, 1, 6, 0U, 0, 0U, 0);
  c34_y = c34_i44;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_sfEvent;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  int32_T c34_y;
  SFc34_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc34_juecefinishiInstanceStruct *)chartInstanceVoid;
  c34_b_sfEvent = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_sfEvent),
    &c34_thisId);
  sf_mex_destroy(&c34_b_sfEvent);
  *(int32_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static uint8_T c34_h_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_juecefinishi, const char_T *
  c34_identifier)
{
  uint8_T c34_y;
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c34_b_is_active_c34_juecefinishi), &c34_thisId);
  sf_mex_destroy(&c34_b_is_active_c34_juecefinishi);
  return c34_y;
}

static uint8_T c34_i_emlrt_marshallIn(SFc34_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  uint8_T c34_y;
  uint8_T c34_u0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_u0, 1, 3, 0U, 0, 0U, 0);
  c34_y = c34_u0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_b_eml_xgemm(SFc34_juecefinishiInstanceStruct *chartInstance,
  real_T c34_A[9], real_T c34_B[3], real_T c34_C[3])
{
  int32_T c34_i45;
  int32_T c34_i46;
  int32_T c34_i47;
  (void)chartInstance;
  for (c34_i45 = 0; c34_i45 < 3; c34_i45++) {
    c34_C[c34_i45] = 0.0;
    c34_i46 = 0;
    for (c34_i47 = 0; c34_i47 < 3; c34_i47++) {
      c34_C[c34_i45] += c34_A[c34_i46 + c34_i45] * c34_B[c34_i47];
      c34_i46 += 3;
    }
  }
}

static void init_dsm_address_info(SFc34_juecefinishiInstanceStruct
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

void sf_c34_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(994373704U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1068479439U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2226190733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4219276356U);
}

mxArray *sf_c34_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("P07AAVHalmsrSFxwTlGR6D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

mxArray *sf_c34_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c34_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c34_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c34_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c34_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc34_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc34_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           34,
           1,
           1,
           0,
           3,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,476);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c34_u1)[3];
          real_T (*c34_y)[3];
          real_T (*c34_u2)[3];
          c34_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c34_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c34_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c34_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c34_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c34_u2);
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
  return "3VZwEK3OLgpDOcuW9okD1B";
}

static void sf_opaque_initialize_c34_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc34_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c34_juecefinishi(void *chartInstanceVar)
{
  enable_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c34_juecefinishi(void *chartInstanceVar)
{
  disable_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c34_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c34_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c34_juecefinishi
    ((SFc34_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c34_juecefinishi();/* state var info */
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

extern void sf_internal_set_sim_state_c34_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c34_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c34_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c34_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c34_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c34_juecefinishi(S, st);
}

static void sf_opaque_terminate_c34_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc34_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
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
  initSimStructsc34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c34_juecefinishi(SimStruct *S)
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
    initialize_params_c34_juecefinishi((SFc34_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c34_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      34);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,34,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,34,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,34);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,34,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,34,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,34);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2434366466U));
  ssSetChecksum1(S,(3018382041U));
  ssSetChecksum2(S,(3170263376U));
  ssSetChecksum3(S,(4050305238U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c34_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c34_juecefinishi(SimStruct *S)
{
  SFc34_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc34_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc34_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc34_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c34_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c34_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c34_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c34_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c34_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c34_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c34_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c34_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c34_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c34_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c34_juecefinishi;
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

void c34_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c34_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c34_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c34_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c34_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
