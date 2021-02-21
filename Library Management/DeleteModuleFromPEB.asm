
    KLIST_ENTRY struct
        Flink dd ?
        Blink dd ?
    KLIST_ENTRY ends

    UNICODE_STRING struct
        CLength dw ?
        MaximumLength dw ?
        Buffer dd ?
    UNICODE_STRING ends

    LDR_DATA_TABLE_ENTRY struct
        InLoadOrderLinks KLIST_ENTRY <>
        InMemoryOrderLinks KLIST_ENTRY <>
        InInitializationOrderLinks KLIST_ENTRY <>
        DllBase dd ?
        EntryPoint dd ?
        SizeOfImage dd ?
        FullDllName UNICODE_STRING <>
        BaseDllName UNICODE_STRING <>
    LDR_DATA_TABLE_ENTRY ends

    PEB_LDR_DATA struct
        dd 3 dup(?)
        InLoadOrderModuleList KLIST_ENTRY <>
        InMemoryOrderModuleList KLIST_ENTRY <>
        InInitializationOrderModuleList KLIST_ENTRY <>
    PEB_LDR_DATA ends

    PEB struct
        db 2 dup(?)
        BeingDebugged db ?
        db ?
        dd 2 dup(?)
        Ldr dd ?
    PEB ends

    DeleteModuleFromPEB proto :dword
    DeleteModuleFromPEB2 proto :dword

.code
; ##########################################################################
DeleteModuleFromPEB proc UnicodeModuleName:dword

    push edi
    push esi

    assume fs:nothing
    mov esi, fs:48

    assume esi:ptr PEB
    mov esi, [esi].Ldr

    assume esi:ptr PEB_LDR_DATA
    mov esi, [esi].InLoadOrderModuleList.Flink
    mov edi, esi

    assume esi:ptr LDR_DATA_TABLE_ENTRY

    .repeat

        mov ecx, [esi].BaseDllName.Buffer

        .if ecx != 0

            invoke lstrcmpiW, ecx, UnicodeModuleName

            .if eax == 0

                assume eax:ptr LDR_DATA_TABLE_ENTRY
                assume ecx:ptr LDR_DATA_TABLE_ENTRY

                mov eax, [esi].InLoadOrderLinks.Flink       ; Make the previous and next Data Tables
                mov ecx, [esi].InLoadOrderLinks.Blink       ; skip over the Entry we want to hide
                mov [ecx].InLoadOrderLinks.Flink, eax
                mov [eax].InLoadOrderLinks.Blink, ecx

                mov eax, [esi].InMemoryOrderLinks.Flink     ; Make the previous and next Data Tables
                mov ecx, [esi].InMemoryOrderLinks.Blink     ; skip over the Entry we want to hide.
                mov [ecx].InLoadOrderLinks.Flink, eax       ; These lines are ILOL because the struct
                mov [eax].InLoadOrderLinks.Blink, ecx       ; points to IMOL!

                .break

            .endif

        .endif

        mov esi, [esi].InLoadOrderLinks.Flink

    .until esi == edi

    pop esi
    pop edi

    ret

DeleteModuleFromPEB endp
; ##########################################################################