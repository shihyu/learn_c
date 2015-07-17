# C 型態



- C data types 分成整數(二補數), 浮點數(IEEE754)

```
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("char size=%ld\n",sizeof(char));
    printf("signed char size=%ld\n",sizeof(signed char));
    printf("unsigned char size=%ld\n",sizeof(unsigned char));
    printf("short size=%ld\n",sizeof(short));
    printf("short int size=%ld\n",sizeof(short int));
    printf("signed short size=%ld\n",sizeof(signed short));
    printf("signed short int size=%ld\n",sizeof(signed short int));
    printf("unsigned short size=%ld\n",sizeof(unsigned short));
    printf("unsigned short int size=%ld\n",sizeof(unsigned short int));
    printf("int size=%ld\n",sizeof(int));
    printf("signed int size=%ld\n",sizeof(signed int));
    printf("unsigned size=%ld\n",sizeof(unsigned));
    printf("unsigned int size=%ld\n",sizeof(unsigned int));
    printf("long size=%ld\n",sizeof(long));
    printf("long int size=%ld\n",sizeof(long int));
    printf("signed long size=%ld\n",sizeof(signed long));
    printf("signed long int size=%ld\n",sizeof(signed long int));
    printf("unsigned long size=%ld\n",sizeof(unsigned long));
    printf("unsigned long int size=%ld\n",sizeof(unsigned long int));
    printf("long long size=%ld\n",sizeof(long long));
    printf("long long int size=%ld\n",sizeof(long long int));
    printf("signed long long size=%ld\n",sizeof(signed long long));
    printf("signed long long int size=%ld\n",sizeof(signed long long int));
    printf("unsigned long long size=%ld\n",sizeof(unsigned long long));
    printf("unsigned long long int size=%ld\n",sizeof(unsigned long long int));
    printf("float size=%ld\n",sizeof(float));
    printf("double size=%ld\n",sizeof(double));
    printf("long double size=%ld\n",sizeof(long double));

    // 32bit CPU 指標佔4byte , 64bit CPU 佔 8byte
    printf("\n\n\n\nchar* size=%ld\n",sizeof(char*));
    printf("signed char* size=%ld\n",sizeof(signed char*));
    printf("unsigned char* size=%ld\n",sizeof(unsigned char*));
    printf("short* size=%ld\n",sizeof(short*));
    printf("short int* size=%ld\n",sizeof(short int*));
    printf("signed short* size=%ld\n",sizeof(signed short*));
    printf("signed short int* size=%ld\n",sizeof(signed short int*));
    printf("unsigned short* size=%ld\n",sizeof(unsigned short*));
    printf("unsigned short int* size=%ld\n",sizeof(unsigned short int*));
    printf("int* size=%ld\n",sizeof(int*));
    printf("signed int* size=%ld\n",sizeof(signed int*));
    printf("unsigned* size=%ld\n",sizeof(unsigned*));
    printf("unsigned int* size=%ld\n",sizeof(unsigned int*));
    printf("long* size=%ld\n",sizeof(long*));
    printf("long int* size=%ld\n",sizeof(long int*));
    printf("signed long* size=%ld\n",sizeof(signed long*));
    printf("signed long int* size=%ld\n",sizeof(signed long int*));
    printf("unsigned long* size=%ld\n",sizeof(unsigned long*));
    printf("unsigned long int* size=%ld\n",sizeof(unsigned long int*));
    printf("long long* size=%ld\n",sizeof(long long*));
    printf("long long int* size=%ld\n",sizeof(long long int*));
    printf("signed long long* size=%ld\n",sizeof(signed long long*));
    printf("signed long long* int size=%ld\n",sizeof(signed long long int*));
    printf("unsigned long long* size=%ld\n",sizeof(unsigned long long*));
    printf("unsigned long long int* size=%ld\n",sizeof(unsigned long long int*));
    printf("float* size=%ld\n",sizeof(float*));
    printf("double* size=%ld\n",sizeof(double*));
    printf("long double* size=%ld\n",sizeof(long double*));
    printf("void* size=%ld\n",sizeof(void*));

    return 0;
}

```


#C data types

<table class="wikitable">
<tr>
<th style="width:14em;">Type</th>
<th>Explanation</th>
<th>Format Specifier</th>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">char</span></code></td>
<td>Smallest addressable unit of the machine that can contain basic character set. It is an integer type. Actual type can be either signed or unsigned depending on the implementation.</td>
<td>&#160;%c</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">signed</span> <span class="kt">char</span></code></td>
<td>Of the same size as <code>char</code>, but guaranteed to be signed.</td>
<td>&#160;%c <small>(or&#160;%hhi for numerical output)</small></td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">char</span></code></td>
<td>Of the same size as <code>char</code>, but guaranteed to be unsigned.</td>
<td>&#160;%c <small>(or&#160;%hhu for numerical output)</small></td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">short</span></code><br />
<code class="mw-highlight"><span class="kt">short</span> <span class="kt">int</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">short</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">short</span> <span class="kt">int</span></code></td>
<td><i>Short</i> signed integer type. Capable of containing at least the [−32767,+32767] range;<sup id="cite_ref-c99sizes_3-0" class="reference"><a href="#cite_note-c99sizes-3"><span>[</span>3<span>]</span></a></sup> thus, it is at least 16 bits in size.</td>
<td>&#160;%hi</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">short</span></code><br />
<code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">short</span> <span class="kt">int</span></code></td>
<td>The same as <code>short</code>, but unsigned.</td>
<td>&#160;%hu</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">int</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">int</span></code></td>
<td>Basic signed integer type. Capable of containing at least the [−32767,+32767] range;<sup id="cite_ref-c99sizes_3-1" class="reference"><a href="#cite_note-c99sizes-3"><span>[</span>3<span>]</span></a></sup> thus, it is at least 16 bits in size.</td>
<td>&#160;%i or&#160;%d</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">unsigned</span></code><br />
<code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">int</span></code></td>
<td>The same as <code>int</code>, but unsigned.</td>
<td>&#160;%u</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">long</span> <span class="kt">int</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">long</span> <span class="kt">int</span></code></td>
<td><i>Long</i> signed integer type. Capable of containing at least the [−2147483647,+2147483647] range;<sup id="cite_ref-c99sizes_3-2" class="reference"><a href="#cite_note-c99sizes-3"><span>[</span>3<span>]</span></a></sup> thus, it is at least 32 bits in size.</td>
<td>&#160;%li</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">long</span> <span class="kt">int</span></code></td>
<td>The same as <code>long</code>, but unsigned.</td>
<td>&#160;%lu</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">long</span> <span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">long</span> <span class="kt">long</span> <span class="kt">int</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">long</span> <span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">signed</span> <span class="kt">long</span> <span class="kt">long</span> <span class="kt">int</span></code></td>
<td><i>Long long</i> signed integer type. Capable of containing at least the [−9223372036854775807,+9223372036854775807] range;<sup id="cite_ref-c99sizes_3-3" class="reference"><a href="#cite_note-c99sizes-3"><span>[</span>3<span>]</span></a></sup> thus, it is at least 64 bits in size. Specified since the <a href="/wiki/C99" title="C99">C99</a> version of the standard.</td>
<td>&#160;%lli</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">long</span> <span class="kt">long</span></code><br />
<code class="mw-highlight"><span class="kt">unsigned</span> <span class="kt">long</span> <span class="kt">long</span> <span class="kt">int</span></code></td>
<td>The same as <code>long long</code>, but unsigned. Specified since the <a href="/wiki/C99" title="C99">C99</a> version of the standard.</td>
<td>&#160;%llu</td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">float</span></code></td>
<td>Real floating-point type, usually referred to as a single-precision floating-point type. Actual properties unspecified (except minimum limits), however on most systems this is the <a href="/wiki/Single-precision_floating-point_format" title="Single-precision floating-point format">IEEE 754 single-precision binary floating-point format</a>. This format is required by the optional Annex F "IEC 60559 floating-point arithmetic".</td>
<td>&#160;%f <small>(promoted automatically to <code>double</code> for <code>printf()</code>)</small></td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">double</span></code></td>
<td>Real floating-point type, usually referred to as a double-precision floating-point type. Actual properties unspecified (except minimum limits), however on most systems this is the <a href="/wiki/Double-precision_floating-point_format" title="Double-precision floating-point format">IEEE 754 double-precision binary floating-point format</a>. This format is required by the optional Annex F "IEC 60559 floating-point arithmetic".</td>
<td>&#160;%f <small>(%lf for <code>scanf()</code>)</small></td>
</tr>
<tr>
<td><code class="mw-highlight"><span class="kt">long</span> <span class="kt">double</span></code></td>
<td>Real floating-point type, usually mapped to an <a href="/wiki/Extended_precision" title="Extended precision">extended precision</a> floating-point number format. Actual properties unspecified. Unlike types <code class="mw-highlight"><span class="kt">float</span></code> and <code class="mw-highlight"><span class="kt">double</span></code>, it can be either <a href="/wiki/80-bit_floating_point_format" title="80-bit floating point format" class="mw-redirect">80-bit floating point format</a>, the non-IEEE "<a href="/wiki/Double-double_arithmetic" title="Double-double arithmetic" class="mw-redirect">double-double</a>" or <a href="/wiki/IEEE_754_quadruple-precision_floating-point_format" title="IEEE 754 quadruple-precision floating-point format" class="mw-redirect">IEEE 754 quadruple-precision floating-point format</a> if a higher precision format is provided, otherwise it is the same as <code class="mw-highlight"><span class="kt">double</span></code>. See <a href="/wiki/Long_double" title="Long double">the article on long double</a> for details.</td>
<td>&#160;%Lf</td>
</tr>
</table>
