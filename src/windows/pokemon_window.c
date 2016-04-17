/**
 * Pokemon information screen
 */
#include "text_animation_window.h"

// STATIC RESOURCES

// Pokemon Resource ID's, macros evaluated at 
// compile time. 
static uint8_t PKMN_ICONS[] = {
    // RESOURCE_ID_0, Throwaway for  MissingNo
    RESOURCE_ID_1,
    RESOURCE_ID_2,
    RESOURCE_ID_3,
    RESOURCE_ID_4,
    RESOURCE_ID_5,
    RESOURCE_ID_6,
    RESOURCE_ID_7,
    RESOURCE_ID_8,
    RESOURCE_ID_9,
    RESOURCE_ID_10,
    RESOURCE_ID_11,
    RESOURCE_ID_12,
    RESOURCE_ID_13,
    RESOURCE_ID_14,
    RESOURCE_ID_15,
    RESOURCE_ID_16,
    RESOURCE_ID_17,
    RESOURCE_ID_18,
    RESOURCE_ID_19,
    RESOURCE_ID_20,
    RESOURCE_ID_21,
    RESOURCE_ID_22,
    RESOURCE_ID_23,
    RESOURCE_ID_24,
    RESOURCE_ID_25,
    RESOURCE_ID_26,
    RESOURCE_ID_27,
    RESOURCE_ID_28,
    RESOURCE_ID_29,
    RESOURCE_ID_30,
    RESOURCE_ID_31,
    RESOURCE_ID_32,
    RESOURCE_ID_33,
    RESOURCE_ID_34,
    RESOURCE_ID_35,
    RESOURCE_ID_36,
    RESOURCE_ID_37,
    RESOURCE_ID_38,
    RESOURCE_ID_39,
    RESOURCE_ID_40,
    RESOURCE_ID_41,
    RESOURCE_ID_42,
    RESOURCE_ID_43,
    RESOURCE_ID_44,
    RESOURCE_ID_45,
    RESOURCE_ID_46,
    RESOURCE_ID_47,
    RESOURCE_ID_48,
    RESOURCE_ID_49,
    RESOURCE_ID_50,
    RESOURCE_ID_51,
    RESOURCE_ID_52,
    RESOURCE_ID_53,
    RESOURCE_ID_54,
    RESOURCE_ID_55,
    RESOURCE_ID_56,
    RESOURCE_ID_57,
    RESOURCE_ID_58,
    RESOURCE_ID_59,
    RESOURCE_ID_60,
    RESOURCE_ID_61,
    RESOURCE_ID_62,
    RESOURCE_ID_63,
    RESOURCE_ID_64,
    RESOURCE_ID_65,
    RESOURCE_ID_66,
    RESOURCE_ID_67,
    RESOURCE_ID_68,
    RESOURCE_ID_69,
    RESOURCE_ID_70,
    RESOURCE_ID_71,
    RESOURCE_ID_72,
    RESOURCE_ID_73,
    RESOURCE_ID_74,
    RESOURCE_ID_75,
    RESOURCE_ID_76,
    RESOURCE_ID_77,
    RESOURCE_ID_78,
    RESOURCE_ID_79,
    RESOURCE_ID_80,
    RESOURCE_ID_81,
    RESOURCE_ID_82,
    RESOURCE_ID_83,
    RESOURCE_ID_84,
    RESOURCE_ID_85,
    RESOURCE_ID_86,
    RESOURCE_ID_87,
    RESOURCE_ID_88,
    RESOURCE_ID_89,
    RESOURCE_ID_90,
    RESOURCE_ID_91,
    RESOURCE_ID_92,
    RESOURCE_ID_93,
    RESOURCE_ID_94,
    RESOURCE_ID_95,
    RESOURCE_ID_96,
    RESOURCE_ID_97,
    RESOURCE_ID_98,
    RESOURCE_ID_99,
    RESOURCE_ID_100,
    RESOURCE_ID_101,
    RESOURCE_ID_102,
    RESOURCE_ID_103,
    RESOURCE_ID_104,
    RESOURCE_ID_105,
    RESOURCE_ID_106,
    RESOURCE_ID_107,
    RESOURCE_ID_108,
    RESOURCE_ID_109,
    RESOURCE_ID_110,
    RESOURCE_ID_111,
    RESOURCE_ID_112,
    RESOURCE_ID_113,
    RESOURCE_ID_114,
    RESOURCE_ID_115,
    RESOURCE_ID_116,
    RESOURCE_ID_117,
    RESOURCE_ID_118,
    RESOURCE_ID_119,
    RESOURCE_ID_120,
    RESOURCE_ID_121,
    RESOURCE_ID_122,
    RESOURCE_ID_123,
    RESOURCE_ID_124,
    RESOURCE_ID_125,
    RESOURCE_ID_126,
    RESOURCE_ID_127,
    RESOURCE_ID_128,
    RESOURCE_ID_129,
    RESOURCE_ID_130,
    RESOURCE_ID_131,
    RESOURCE_ID_132,
    RESOURCE_ID_133,
    RESOURCE_ID_134,
    RESOURCE_ID_135,
    RESOURCE_ID_136,
    RESOURCE_ID_137,
    RESOURCE_ID_138,
    RESOURCE_ID_139,
    RESOURCE_ID_140,
    RESOURCE_ID_141,
    RESOURCE_ID_142,
    RESOURCE_ID_143,
    RESOURCE_ID_144,
    RESOURCE_ID_145,
    RESOURCE_ID_146,
    RESOURCE_ID_147,
    RESOURCE_ID_148,
    RESOURCE_ID_149,
    RESOURCE_ID_150,
    RESOURCE_ID_151,
    RESOURCE_ID_152,
	RESOURCE_ID_153,
	RESOURCE_ID_154,
	RESOURCE_ID_155,
	RESOURCE_ID_156,
	RESOURCE_ID_157,
	RESOURCE_ID_158,
	RESOURCE_ID_159,
	RESOURCE_ID_160,
	RESOURCE_ID_161,
	RESOURCE_ID_162,
	RESOURCE_ID_163,
	RESOURCE_ID_164,
	RESOURCE_ID_165,
	RESOURCE_ID_166,
	RESOURCE_ID_167,
	RESOURCE_ID_168,
	RESOURCE_ID_169,
	RESOURCE_ID_170,
	RESOURCE_ID_171,
	RESOURCE_ID_172,
	RESOURCE_ID_173,
	RESOURCE_ID_174,
	RESOURCE_ID_175,
	RESOURCE_ID_176,
	RESOURCE_ID_177,
	RESOURCE_ID_178,
	RESOURCE_ID_179,
	RESOURCE_ID_180,
	RESOURCE_ID_181,
	RESOURCE_ID_182,
	RESOURCE_ID_183,
	RESOURCE_ID_184,
	RESOURCE_ID_185,
	RESOURCE_ID_186,
	RESOURCE_ID_187,
	RESOURCE_ID_188,
	RESOURCE_ID_189,
	RESOURCE_ID_190,
	RESOURCE_ID_191,
	RESOURCE_ID_192,
	RESOURCE_ID_193,
	RESOURCE_ID_194,
	RESOURCE_ID_195,
	RESOURCE_ID_196,
	RESOURCE_ID_197,
	RESOURCE_ID_198,
	RESOURCE_ID_199,
	RESOURCE_ID_200,
	RESOURCE_ID_201,
	RESOURCE_ID_202,
	RESOURCE_ID_203,
	RESOURCE_ID_204,
	RESOURCE_ID_205,
	RESOURCE_ID_206,
	RESOURCE_ID_207,
	RESOURCE_ID_208,
	RESOURCE_ID_209,
	RESOURCE_ID_210,
	RESOURCE_ID_211,
	RESOURCE_ID_212,
	RESOURCE_ID_213,
	RESOURCE_ID_214,
	RESOURCE_ID_215,
	RESOURCE_ID_216,
	RESOURCE_ID_217,
	RESOURCE_ID_218,
	RESOURCE_ID_219,
	RESOURCE_ID_220,
	RESOURCE_ID_221,
	RESOURCE_ID_222,
	RESOURCE_ID_223,
	RESOURCE_ID_224,
	RESOURCE_ID_225,
	RESOURCE_ID_226,
	RESOURCE_ID_227,
	RESOURCE_ID_228,
	RESOURCE_ID_229,
	RESOURCE_ID_230,
	RESOURCE_ID_231,
	RESOURCE_ID_232,
	RESOURCE_ID_233,
	RESOURCE_ID_234,
	RESOURCE_ID_235,
	RESOURCE_ID_236,
	RESOURCE_ID_237,
	RESOURCE_ID_238,
	RESOURCE_ID_239,
	RESOURCE_ID_240,
	RESOURCE_ID_241,
    /* full resource pack
	RESOURCE_ID_242,
	RESOURCE_ID_243,
	RESOURCE_ID_244,
	RESOURCE_ID_245,
	RESOURCE_ID_246,
	RESOURCE_ID_247,
	RESOURCE_ID_248,
	RESOURCE_ID_249,
	RESOURCE_ID_250,
	RESOURCE_ID_251
    */
    
};

// Window Variables
static Window *s_window;

// Bitmap Variables
static GBitmapSequence *s_sequence;
static GBitmap *s_bitmap;
static BitmapLayer *s_bitmap_layer;

static void timer_handler(void *context) {
  uint32_t next_delay;

  // Advance to the next APNG frame, and get the delay for this frame
  if(gbitmap_sequence_update_bitmap_next_frame(s_sequence, s_bitmap, &next_delay)) {
    // Set the new frame into the BitmapLayer
    bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
    layer_mark_dirty(bitmap_layer_get_layer(s_bitmap_layer));

    // Timer for that frame's delay
    app_timer_register(next_delay, timer_handler, NULL);
  }
}


static void animate(int pkmn_number){
// perform all animation

    // create sequence to display series of frames of an apng
    s_sequence = gbitmap_sequence_create_with_resource(PKMN_ICONS[ pkmn_number ]);

    // Create blank GBitmap using APNG frame size
    GSize frame_size = gbitmap_sequence_get_bitmap_size(s_sequence);
    s_bitmap = gbitmap_create_blank(frame_size, GBitmapFormat8Bit);

    s_bitmap_layer = bitmap_layer_create(GRect(40, 40, 60, 60));
    bitmap_layer_set_compositing_mode(s_bitmap_layer, GCompOpSet);
    bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);

    // add child layer to s_window
    layer_add_child(window_get_root_layer(s_window), bitmap_layer_get_layer(s_bitmap_layer));

    // timer for frame delay
	uint32_t first_delay_ms = 10;
	// Schedule a timer to advance the first frame
	app_timer_register(first_delay_ms, timer_handler, NULL);
}

static void window_load(){
}

static void window_unload(){
    // clear resources
    bitmap_layer_destroy(s_bitmap_layer);
    gbitmap_sequence_destroy(s_sequence);
    gbitmap_destroy(s_bitmap);
    window_destroy(s_window);
    s_window = NULL; 
}

static void window_disappear(){
}

void pkmn_window_push(int pkmn_number){
  //`snprintf(s_text[0], sizeof(s_text[0]), "Bulbasaur!");

  if(!s_window) {
    s_window = window_create();
    window_set_background_color(s_window, GColorWhite);
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
      .disappear = window_disappear
    });
  }
  window_stack_push(s_window, true);

  animate(pkmn_number);
}

