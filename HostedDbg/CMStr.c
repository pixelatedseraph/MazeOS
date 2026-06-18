#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "Types.h"
#include "TestStringLib.h"

static void test_string_length(void **state)
{
    (void)state;

    assert_uint_equal(ESTR_StringLength(u"Hello World"),11);
    assert_uint_equal(ESTR_StringLength(u""),0);
    assert_uint_equal(ESTR_StringLength(u"a"),1);
    assert_uint_equal(ESTR_StringLength(u" abc "),5);
    assert_uint_equal(ESTR_StringLength(u"1234567890scdbqkdbvhBWDkbe vhq S 2EUKU FVEJK SCAJBEFFEBU;WEFBUBJKVWE JKSVDIUQF3biwve KJFEFW4 3B8PQ3R3OR3RFBEFWUIHWF  Usas8hoafwlawdbifwo;qfwqn hxuwb"),148);
    assert_uint_equal(ESTR_StringLength(u"FUCJCHDUK hv k3g 3vbfesbfey#$%^&**&@^%R#^&*$&^&*Q((@#*(*&FBU& @ *HGF &U#GF L<U@GR*& !WGY@R:YOUGYU@LW>IUDYCFVU YHIFG>L^bf gcxi5c6guRX&U GD%P D* ^8HTG  ddwfgufbu4thkj fjI  U   UU          UIG4GWIUFHO 9UW3R3 RGV J29ECCBVNBbxcbfbfhigehrgn ccjsbiqorovegvcob mcbjhfufeheiuy4uiqowifughfidjfhvjckdjvhbvjkdjdhfjkdsjdhfjdskasjdbvf45267389405t987r7ew8q90w9e8rygfhjdkldkcmnv vnjde3745849302938rtygjfkdlsdkjhr5tyuropdlkjr578940w-pslkdmcvmcklsaqas,c.lfkgf,relwq1iuwerielw,smdnfhru4io3elrtjytroepsowe948493op ;laksdfhjfck mnvh)))"),514);
}

static void test_memcpy(void **state)
{
    (void)state;

    assert_uint_equal(ESTR_StringLength(u"Hello World"),11);
    assert_uint_equal(ESTR_StringLength(u""),0);
    assert_uint_equal(ESTR_StringLength(u"a"),1);
    assert_uint_equal(ESTR_StringLength(u" abc "),5);
    assert_uint_equal(ESTR_StringLength(u"1234567890scdbqkdbvhBWDkbe vhq S 2EUKU FVEJK SCAJBEFFEBU;WEFBUBJKVWE JKSVDIUQF3biwve KJFEFW4 3B8PQ3R3OR3RFBEFWUIHWF  Usas8hoafwlawdbifwo;qfwqn hxuwb"),148);
    assert_uint_equal(ESTR_StringLength(u"FUCJCHDUK hv k3g 3vbfesbfey#$%^&**&@^%R#^&*$&^&*Q((@#*(*&FBU& @ *HGF &U#GF L<U@GR*& !WGY@R:YOUGYU@LW>IUDYCFVU YHIFG>L^bf gcxi5c6guRX&U GD%P D* ^8HTG  ddwfgufbu4thkj fjI  U   UU          UIG4GWIUFHO 9UW3R3 RGV J29ECCBVNBbxcbfbfhigehrgn ccjsbiqorovegvcob mcbjhfufeheiuy4uiqowifughfidjfhvjckdjvhbvjkdjdhfjkdsjdhfjdskasjdbvf45267389405t987r7ew8q90w9e8rygfhjdkldkcmnv vnjde3745849302938rtygjfkdlsdkjhr5tyuropdlkjr578940w-pslkdmcvmcklsaqas,c.lfkgf,relwq1iuwerielw,smdnfhru4io3elrtjytroepsowe948493op ;laksdfhjfck mnvh)))"),514);
}


int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_string_length),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}