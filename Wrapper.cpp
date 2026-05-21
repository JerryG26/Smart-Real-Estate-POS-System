#include <napi.h>
#include <iostream>
#include "src/InventoryManager.cpp" // Includes your existing manager logic

// This function acts as the middleman between JS and C++
Napi::Value GetInventoryStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Example: Instantiating your actual C++ class
    InventoryManager manager; 
    
    // Returning a simple string message back to JavaScript
    return Napi::String::New(env, "Successfully connected to C++ InventoryManager backend!");
}

// Initialize the Node-API module
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // This exposes "getInventoryStatus" as a callable function in JavaScript
    exports.Set(Napi::String::New(env, "getInventoryStatus"), 
                Napi::Function::New(env, GetInventoryStatus));
    return exports;
}

NODE_API_MODULE(addon, Init)