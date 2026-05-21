{
  "targets": [
    {
      "target_name": "backend",
      "sources": [ "Wrapper.cpp" ],
      "include_dirs": [
        "node_modules/node-addon-api",
        "src",
        "hea"
      ],
      "dependencies": [],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
      "msvs_settings": {
        "VCCLCompilerTool": {
          "AdditionalIncludeDirectories": [ "src" ]
        }
      }
    }
  ]
}