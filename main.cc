#include <node.h>

namespace mukti {
  using v8::FunctionCallbackInfo;
  using v8::Value;
  using v8::Isolate;
  using v8::Number;
  using v8::Local;
  using v8::Object;

  void Method(const FunctionCallbackInfo<Value>&args) {
    Isolate* isolate = args.GetIsolate();
    int i;
    double x = 1, y = 3;
    auto total = Number::New(isolate, x + y);
    args.GetReturnValue().Set(total);
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "mc", Method);
  }
  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}