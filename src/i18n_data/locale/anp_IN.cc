﻿#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t monetary_mon_grouping_storage[]{3,2};

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.title=tsc("Angika language locale for India"),.source=tsc("fast_io"),.address=tsc("https://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc("fast_io"),.email=tsc("bhashaghar@googlegroups.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Angika"),.territory=tsc("India"),.revision=tsc("1.0"),.date=tsc("2013-10-24")},.monetary={.int_curr_symbol=tsc("INR "),.currency_symbol=tsc("₹"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("रवि"),tsc("सोम"),tsc("मंगल"),tsc("बुध"),tsc("बृहस्पति"),tsc("शुक्र"),tsc("शनि")},.day={tsc("रविवार"),tsc("सोमवार"),tsc("मंगलवार"),tsc("बुधवार"),tsc("बृहस्पतिवार"),tsc("शुक्रवार"),tsc("शनिवार")},.abmon={tsc("जनवरी"),tsc("फरवरी"),tsc("मार्च"),tsc("अप्रैल"),tsc("मई"),tsc("जून"),tsc("जुलाई"),tsc("अगस्त"),tsc("सितंबर"),tsc("अक्टूबर"),tsc("नवंबर"),tsc("दिसंबर")},.mon={tsc("जनवरी"),tsc("फरवरी"),tsc("मार्च"),tsc("अप्रैल"),tsc("मई"),tsc("जून"),tsc("जुलाई"),tsc("अगस्त"),tsc("सितंबर"),tsc("अक्टूबर"),tsc("नवंबर"),tsc("दिसंबर")},.d_t_fmt=tsc("%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc("%-d//%-m//%y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc("पूर्वाह्न"),tsc("अपराह्न")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1हवyY]"),.noexpr=tsc("^[-0नइnN]"),.yesstr=tsc("हाँ"),.nostr=tsc("नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("91")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc(""),.name_miss=tsc("कुमारी"),.name_mr=tsc("श्री"),.name_mrs=tsc("श्रीमती"),.name_ms=tsc("कुमार")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("भारत"),.country_ab2=tsc("IN"),.country_ab3=tsc("IND"),.country_num=356,.country_car=tsc("IND"),.lang_name=tsc("अंगिका"),.lang_term=tsc("anp"),.lang_lib=tsc("anp")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.title=tsc(L"Angika language locale for India"),.source=tsc(L"fast_io"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bhashaghar@googlegroups.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Angika"),.territory=tsc(L"India"),.revision=tsc(L"1.0"),.date=tsc(L"2013-10-24")},.monetary={.int_curr_symbol=tsc(L"INR "),.currency_symbol=tsc(L"₹"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"रवि"),tsc(L"सोम"),tsc(L"मंगल"),tsc(L"बुध"),tsc(L"बृहस्पति"),tsc(L"शुक्र"),tsc(L"शनि")},.day={tsc(L"रविवार"),tsc(L"सोमवार"),tsc(L"मंगलवार"),tsc(L"बुधवार"),tsc(L"बृहस्पतिवार"),tsc(L"शुक्रवार"),tsc(L"शनिवार")},.abmon={tsc(L"जनवरी"),tsc(L"फरवरी"),tsc(L"मार्च"),tsc(L"अप्रैल"),tsc(L"मई"),tsc(L"जून"),tsc(L"जुलाई"),tsc(L"अगस्त"),tsc(L"सितंबर"),tsc(L"अक्टूबर"),tsc(L"नवंबर"),tsc(L"दिसंबर")},.mon={tsc(L"जनवरी"),tsc(L"फरवरी"),tsc(L"मार्च"),tsc(L"अप्रैल"),tsc(L"मई"),tsc(L"जून"),tsc(L"जुलाई"),tsc(L"अगस्त"),tsc(L"सितंबर"),tsc(L"अक्टूबर"),tsc(L"नवंबर"),tsc(L"दिसंबर")},.d_t_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(L"%-d//%-m//%y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"पूर्वाह्न"),tsc(L"अपराह्न")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1हवyY]"),.noexpr=tsc(L"^[-0नइnN]"),.yesstr=tsc(L"हाँ"),.nostr=tsc(L"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"91")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L""),.name_miss=tsc(L"कुमारी"),.name_mr=tsc(L"श्री"),.name_mrs=tsc(L"श्रीमती"),.name_ms=tsc(L"कुमार")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"भारत"),.country_ab2=tsc(L"IN"),.country_ab3=tsc(L"IND"),.country_num=356,.country_car=tsc(L"IND"),.lang_name=tsc(L"अंगिका"),.lang_term=tsc(L"anp"),.lang_lib=tsc(L"anp")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.title=tsc(u8"Angika language locale for India"),.source=tsc(u8"fast_io"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bhashaghar@googlegroups.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Angika"),.territory=tsc(u8"India"),.revision=tsc(u8"1.0"),.date=tsc(u8"2013-10-24")},.monetary={.int_curr_symbol=tsc(u8"INR "),.currency_symbol=tsc(u8"₹"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"रवि"),tsc(u8"सोम"),tsc(u8"मंगल"),tsc(u8"बुध"),tsc(u8"बृहस्पति"),tsc(u8"शुक्र"),tsc(u8"शनि")},.day={tsc(u8"रविवार"),tsc(u8"सोमवार"),tsc(u8"मंगलवार"),tsc(u8"बुधवार"),tsc(u8"बृहस्पतिवार"),tsc(u8"शुक्रवार"),tsc(u8"शनिवार")},.abmon={tsc(u8"जनवरी"),tsc(u8"फरवरी"),tsc(u8"मार्च"),tsc(u8"अप्रैल"),tsc(u8"मई"),tsc(u8"जून"),tsc(u8"जुलाई"),tsc(u8"अगस्त"),tsc(u8"सितंबर"),tsc(u8"अक्टूबर"),tsc(u8"नवंबर"),tsc(u8"दिसंबर")},.mon={tsc(u8"जनवरी"),tsc(u8"फरवरी"),tsc(u8"मार्च"),tsc(u8"अप्रैल"),tsc(u8"मई"),tsc(u8"जून"),tsc(u8"जुलाई"),tsc(u8"अगस्त"),tsc(u8"सितंबर"),tsc(u8"अक्टूबर"),tsc(u8"नवंबर"),tsc(u8"दिसंबर")},.d_t_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%-d//%-m//%y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"पूर्वाह्न"),tsc(u8"अपराह्न")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1हवyY]"),.noexpr=tsc(u8"^[-0नइnN]"),.yesstr=tsc(u8"हाँ"),.nostr=tsc(u8"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"91")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8""),.name_miss=tsc(u8"कुमारी"),.name_mr=tsc(u8"श्री"),.name_mrs=tsc(u8"श्रीमती"),.name_ms=tsc(u8"कुमार")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"भारत"),.country_ab2=tsc(u8"IN"),.country_ab3=tsc(u8"IND"),.country_num=356,.country_car=tsc(u8"IND"),.lang_name=tsc(u8"अंगिका"),.lang_term=tsc(u8"anp"),.lang_lib=tsc(u8"anp")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.title=tsc(u"Angika language locale for India"),.source=tsc(u"fast_io"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bhashaghar@googlegroups.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Angika"),.territory=tsc(u"India"),.revision=tsc(u"1.0"),.date=tsc(u"2013-10-24")},.monetary={.int_curr_symbol=tsc(u"INR "),.currency_symbol=tsc(u"₹"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"रवि"),tsc(u"सोम"),tsc(u"मंगल"),tsc(u"बुध"),tsc(u"बृहस्पति"),tsc(u"शुक्र"),tsc(u"शनि")},.day={tsc(u"रविवार"),tsc(u"सोमवार"),tsc(u"मंगलवार"),tsc(u"बुधवार"),tsc(u"बृहस्पतिवार"),tsc(u"शुक्रवार"),tsc(u"शनिवार")},.abmon={tsc(u"जनवरी"),tsc(u"फरवरी"),tsc(u"मार्च"),tsc(u"अप्रैल"),tsc(u"मई"),tsc(u"जून"),tsc(u"जुलाई"),tsc(u"अगस्त"),tsc(u"सितंबर"),tsc(u"अक्टूबर"),tsc(u"नवंबर"),tsc(u"दिसंबर")},.mon={tsc(u"जनवरी"),tsc(u"फरवरी"),tsc(u"मार्च"),tsc(u"अप्रैल"),tsc(u"मई"),tsc(u"जून"),tsc(u"जुलाई"),tsc(u"अगस्त"),tsc(u"सितंबर"),tsc(u"अक्टूबर"),tsc(u"नवंबर"),tsc(u"दिसंबर")},.d_t_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u"%-d//%-m//%y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"पूर्वाह्न"),tsc(u"अपराह्न")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1हवyY]"),.noexpr=tsc(u"^[-0नइnN]"),.yesstr=tsc(u"हाँ"),.nostr=tsc(u"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"91")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u""),.name_miss=tsc(u"कुमारी"),.name_mr=tsc(u"श्री"),.name_mrs=tsc(u"श्रीमती"),.name_ms=tsc(u"कुमार")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"भारत"),.country_ab2=tsc(u"IN"),.country_ab3=tsc(u"IND"),.country_num=356,.country_car=tsc(u"IND"),.lang_name=tsc(u"अंगिका"),.lang_term=tsc(u"anp"),.lang_lib=tsc(u"anp")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.title=tsc(U"Angika language locale for India"),.source=tsc(U"fast_io"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bhashaghar@googlegroups.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Angika"),.territory=tsc(U"India"),.revision=tsc(U"1.0"),.date=tsc(U"2013-10-24")},.monetary={.int_curr_symbol=tsc(U"INR "),.currency_symbol=tsc(U"₹"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"रवि"),tsc(U"सोम"),tsc(U"मंगल"),tsc(U"बुध"),tsc(U"बृहस्पति"),tsc(U"शुक्र"),tsc(U"शनि")},.day={tsc(U"रविवार"),tsc(U"सोमवार"),tsc(U"मंगलवार"),tsc(U"बुधवार"),tsc(U"बृहस्पतिवार"),tsc(U"शुक्रवार"),tsc(U"शनिवार")},.abmon={tsc(U"जनवरी"),tsc(U"फरवरी"),tsc(U"मार्च"),tsc(U"अप्रैल"),tsc(U"मई"),tsc(U"जून"),tsc(U"जुलाई"),tsc(U"अगस्त"),tsc(U"सितंबर"),tsc(U"अक्टूबर"),tsc(U"नवंबर"),tsc(U"दिसंबर")},.mon={tsc(U"जनवरी"),tsc(U"फरवरी"),tsc(U"मार्च"),tsc(U"अप्रैल"),tsc(U"मई"),tsc(U"जून"),tsc(U"जुलाई"),tsc(U"अगस्त"),tsc(U"सितंबर"),tsc(U"अक्टूबर"),tsc(U"नवंबर"),tsc(U"दिसंबर")},.d_t_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(U"%-d//%-m//%y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"पूर्वाह्न"),tsc(U"अपराह्न")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1हवyY]"),.noexpr=tsc(U"^[-0नइnN]"),.yesstr=tsc(U"हाँ"),.nostr=tsc(U"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"91")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U""),.name_miss=tsc(U"कुमारी"),.name_mr=tsc(U"श्री"),.name_mrs=tsc(U"श्रीमती"),.name_ms=tsc(U"कुमार")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"भारत"),.country_ab2=tsc(U"IN"),.country_ab3=tsc(U"IND"),.country_num=356,.country_car=tsc(U"IND"),.lang_name=tsc(U"अंगिका"),.lang_term=tsc(U"anp"),.lang_lib=tsc(U"anp")},.measurement={.measurement=1}};


}
}

#include"../main.h"