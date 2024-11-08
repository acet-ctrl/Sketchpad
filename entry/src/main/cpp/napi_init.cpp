#include <charconv>
#include <cstdint>
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <hilog/log.h>
#include <napi/native_api.h>

// #include "controller.h"
// #include "store.h"

namespace Engine {
static napi_value LoadRdb(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv = nullptr;
    napi_get_cb_info(env, info, &argc, &argv, nullptr, nullptr);
    size_t length = 0;
    napi_get_value_string_utf8(env, argv, nullptr, 0, &length);
    auto buf = new char[length + 1]();
    napi_get_value_string_utf8(env, argv, buf, length + 1, &length);
    // RdbStore::Init(buf);
    delete[] buf;
    // Controller::Init();
    return nullptr;
}

static napi_value LoadData(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv = nullptr;
    napi_get_cb_info(env, info, &argc, &argv, nullptr, nullptr);

    uint32_t id;
    napi_get_value_uint32(env, argv, &id);
    // Controller::GetInstance()->Load(id);

    return nullptr;
}

EXTERN_C_START
static napi_value Napi_Init(napi_env env, napi_value exports) {
    napi_value exportInstance = nullptr;
    napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);

    OH_NativeXComponent *xComponent = nullptr;
    napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&xComponent));
    
    napi_property_descriptor desc[] = {{"init", nullptr, LoadRdb, nullptr, nullptr, nullptr, napi_default, nullptr},
                                       {"load", nullptr, LoadData, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module engineModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Napi_Init,
    .nm_modname = "engine",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEngineModule() { napi_module_register(&engineModule); }
}