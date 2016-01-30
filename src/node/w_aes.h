#ifndef OSSL_W_AES_H_INCLUDE
#define OSSL_W_AES_H_INCLUDE

#include "../core/common.h"
#include "../aes/common.h"
#include "async_aes.h"

using namespace node;

class WAes: public ObjectWrap {
public:
	static v8::Local<v8::Object> NewInstance() {
		v8::Local<v8::Function> cons = Nan::New(constructor());
		return Nan::NewInstance(cons).ToLocalChecked();
	}
	static v8::Local<v8::Object> NewInstance(int argc, v8::Local<v8::Value> argv[]) {
		v8::Local<v8::Function> cons = Nan::New(constructor());
		return Nan::NewInstance(cons, argc, argv).ToLocalChecked();
	}

	static const char* ClassName;

	static void Init(v8::Handle<v8::Object> exports);
	
	static NAN_METHOD(New);
	
	static NAN_METHOD(Generate);
	static NAN_METHOD(Encrypt);
	static NAN_METHOD(Decrypt);
	static NAN_METHOD(Export);
	static NAN_METHOD(Import);

	Handle<ScopedAES> data;

protected:
	static inline Nan::Persistent<v8::Function> & constructor() {
		static Nan::Persistent<v8::Function> my_constructor;
		return my_constructor;
	}

};

#include "common.h"


#endif // OSSL_W_KEY_H_INCLUDE