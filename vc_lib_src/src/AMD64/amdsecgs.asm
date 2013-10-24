;***
;amdsecgs.asm      - amd64 -GS cookie check compiler helper
;
;       Copyright (c) Microsoft Corporation. All rights reserved.
;
;Purpose:
;       AMD64 security cookie checking routine
;
;*******************************************************************************

        TITLE   "AMD64 GS Security Check Compiler Helper"

include ksamd64.inc

        extern __security_cookie:QWORD
        extern __report_gsfailure:PROC

;*++
;
; VOID
; __security_check_cookie (
;    ULONG64 Value
;    )
;
; Routine Description:
;
;   This function checks the specified cookie value against the global
;   cookie value. If the values match, then control is returned to the
;   caller. Otherwise, the failure is reported and there is no return
;   to the caller.
;
;   N.B. No registers except for RCX are modified if the return is to the
;   caller.
;
; Arguments:
;
;   Value (rcx) - Supplies the value of cookie.
;
; Return Value:
;
;    None.
;
;--*

        LEAF_ENTRY __security_check_cookie, _TEXT

        cmp rcx, __security_cookie      ; check cookie value in frame
        jne ReportFailure               ; if ne, cookie check failure
        rol rcx, 16                     ; make sure high word is zero
        test cx, -1
        jne RestoreRcx
        db 0f3h                         ; (encode REP for REP RET)
        ret                             ; no overrun, use REP RET to avoid AMD
                                        ; branch prediction flaw after Jcc

;
; The cookie check failed.
;

RestoreRcx:
        ror rcx, 16

ReportFailure:

        jmp __report_gsfailure          ; overrun found

        LEAF_END __security_check_cookie, _TEXT

        end
