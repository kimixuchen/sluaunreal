// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once
#include "CoreMinimal.h"
#include "lua/lua.hpp"

namespace NS_SLUA {

//#if WITH_EDITOR
	struct LuaMemInfo {
        FString hint;
        int size;
        void* ptr;

		int push(lua_State* L) const;
	};
    
    // << used to binary for LuaMemInfo data
    FORCEINLINE FArchive& operator<<(FArchive &Ar, LuaMemInfo& Info)
    {
        Ar << Info.hint;
        Ar << Info.size;
        
        return Ar;
    }

	typedef TMap<void*, LuaMemInfo> MemoryDetail;
//#endif

    class LuaMemoryProfile {
    public:
        static void* alloc (void *ud, void *ptr, size_t osize, size_t nsize);
		static SLUA_UNREAL_API size_t total();
//#if WITH_EDITOR
		static SLUA_UNREAL_API void start();
		static SLUA_UNREAL_API void stop();
		static const MemoryDetail& memDetail();       
//#endif
    };

}
