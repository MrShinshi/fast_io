﻿#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t monetary_mon_grouping_storage[]{3,2};

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.title=tsc("Bodo language locale for India"),.source=tsc("Red Hat Pune\t\t;\t\tfast_io"),.address=tsc("Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc("fast_io"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Bodo"),.territory=tsc("India"),.revision=tsc("1.0"),.date=tsc("2011-10-17")},.monetary={.int_curr_symbol=tsc("INR "),.currency_symbol=tsc("₹"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("रबि"),tsc("सम"),tsc("मंगल"),tsc("बुद"),tsc("बिसथि"),tsc("सुखुर"),tsc("सुनि")},.day={tsc("रबिबार"),tsc("सोबार"),tsc("मंगलबार"),tsc("बुदबार"),tsc("बिसथिबार"),tsc("सुखुरबार"),tsc("सुनिबार")},.abmon={tsc("जानुवारी"),tsc("फेब्रुवारी"),tsc("मार्स"),tsc("एप्रिल"),tsc("मे"),tsc("जुन"),tsc("जुलाइ"),tsc("आगस्थ"),tsc("सेबथेज्ब़र"),tsc("अखथबर"),tsc("नबेज्ब़र"),tsc("दिसेज्ब़र")},.mon={tsc("जानुवारी"),tsc("फेब्रुवारी"),tsc("मार्स"),tsc("एफ्रिल"),tsc("मे"),tsc("जुन"),tsc("जुलाइ"),tsc("आगस्थ"),tsc("सेबथेज्ब़र"),tsc("अखथबर"),tsc("नबेज्ब़र"),tsc("दिसेज्ब़र")},.d_t_fmt=tsc("%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc("%-m//%-d//%y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc("फुं."),tsc("बेलासे.")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yYह]"),.noexpr=tsc("^[-0nNन]"),.yesstr=tsc("हाँ"),.nostr=tsc("नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("91")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc(""),.name_miss=tsc("Miss."),.name_mr=tsc("Mr."),.name_mrs=tsc("Mrs."),.name_ms=tsc("Ms.")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("भारत"),.country_ab2=tsc("IN"),.country_ab3=tsc("IND"),.country_num=356,.country_car=tsc("IND"),.lang_name=tsc("बड़ो"),.lang_term=tsc("brx"),.lang_lib=tsc("brx")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.title=tsc(L"Bodo language locale for India"),.source=tsc(L"Red Hat Pune\t\t;\t\tfast_io"),.address=tsc(L"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Bodo"),.territory=tsc(L"India"),.revision=tsc(L"1.0"),.date=tsc(L"2011-10-17")},.monetary={.int_curr_symbol=tsc(L"INR "),.currency_symbol=tsc(L"₹"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"रबि"),tsc(L"सम"),tsc(L"मंगल"),tsc(L"बुद"),tsc(L"बिसथि"),tsc(L"सुखुर"),tsc(L"सुनि")},.day={tsc(L"रबिबार"),tsc(L"सोबार"),tsc(L"मंगलबार"),tsc(L"बुदबार"),tsc(L"बिसथिबार"),tsc(L"सुखुरबार"),tsc(L"सुनिबार")},.abmon={tsc(L"जानुवारी"),tsc(L"फेब्रुवारी"),tsc(L"मार्स"),tsc(L"एप्रिल"),tsc(L"मे"),tsc(L"जुन"),tsc(L"जुलाइ"),tsc(L"आगस्थ"),tsc(L"सेबथेज्ब़र"),tsc(L"अखथबर"),tsc(L"नबेज्ब़र"),tsc(L"दिसेज्ब़र")},.mon={tsc(L"जानुवारी"),tsc(L"फेब्रुवारी"),tsc(L"मार्स"),tsc(L"एफ्रिल"),tsc(L"मे"),tsc(L"जुन"),tsc(L"जुलाइ"),tsc(L"आगस्थ"),tsc(L"सेबथेज्ब़र"),tsc(L"अखथबर"),tsc(L"नबेज्ब़र"),tsc(L"दिसेज्ब़र")},.d_t_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(L"%-m//%-d//%y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"फुं."),tsc(L"बेलासे.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yYह]"),.noexpr=tsc(L"^[-0nNन]"),.yesstr=tsc(L"हाँ"),.nostr=tsc(L"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"91")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L""),.name_miss=tsc(L"Miss."),.name_mr=tsc(L"Mr."),.name_mrs=tsc(L"Mrs."),.name_ms=tsc(L"Ms.")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"भारत"),.country_ab2=tsc(L"IN"),.country_ab3=tsc(L"IND"),.country_num=356,.country_car=tsc(L"IND"),.lang_name=tsc(L"बड़ो"),.lang_term=tsc(L"brx"),.lang_lib=tsc(L"brx")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.title=tsc(u8"Bodo language locale for India"),.source=tsc(u8"Red Hat Pune\t\t;\t\tfast_io"),.address=tsc(u8"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Bodo"),.territory=tsc(u8"India"),.revision=tsc(u8"1.0"),.date=tsc(u8"2011-10-17")},.monetary={.int_curr_symbol=tsc(u8"INR "),.currency_symbol=tsc(u8"₹"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"रबि"),tsc(u8"सम"),tsc(u8"मंगल"),tsc(u8"बुद"),tsc(u8"बिसथि"),tsc(u8"सुखुर"),tsc(u8"सुनि")},.day={tsc(u8"रबिबार"),tsc(u8"सोबार"),tsc(u8"मंगलबार"),tsc(u8"बुदबार"),tsc(u8"बिसथिबार"),tsc(u8"सुखुरबार"),tsc(u8"सुनिबार")},.abmon={tsc(u8"जानुवारी"),tsc(u8"फेब्रुवारी"),tsc(u8"मार्स"),tsc(u8"एप्रिल"),tsc(u8"मे"),tsc(u8"जुन"),tsc(u8"जुलाइ"),tsc(u8"आगस्थ"),tsc(u8"सेबथेज्ब़र"),tsc(u8"अखथबर"),tsc(u8"नबेज्ब़र"),tsc(u8"दिसेज्ब़र")},.mon={tsc(u8"जानुवारी"),tsc(u8"फेब्रुवारी"),tsc(u8"मार्स"),tsc(u8"एफ्रिल"),tsc(u8"मे"),tsc(u8"जुन"),tsc(u8"जुलाइ"),tsc(u8"आगस्थ"),tsc(u8"सेबथेज्ब़र"),tsc(u8"अखथबर"),tsc(u8"नबेज्ब़र"),tsc(u8"दिसेज्ब़र")},.d_t_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%-m//%-d//%y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"फुं."),tsc(u8"बेलासे.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yYह]"),.noexpr=tsc(u8"^[-0nNन]"),.yesstr=tsc(u8"हाँ"),.nostr=tsc(u8"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"91")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8""),.name_miss=tsc(u8"Miss."),.name_mr=tsc(u8"Mr."),.name_mrs=tsc(u8"Mrs."),.name_ms=tsc(u8"Ms.")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"भारत"),.country_ab2=tsc(u8"IN"),.country_ab3=tsc(u8"IND"),.country_num=356,.country_car=tsc(u8"IND"),.lang_name=tsc(u8"बड़ो"),.lang_term=tsc(u8"brx"),.lang_lib=tsc(u8"brx")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.title=tsc(u"Bodo language locale for India"),.source=tsc(u"Red Hat Pune\t\t;\t\tfast_io"),.address=tsc(u"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Bodo"),.territory=tsc(u"India"),.revision=tsc(u"1.0"),.date=tsc(u"2011-10-17")},.monetary={.int_curr_symbol=tsc(u"INR "),.currency_symbol=tsc(u"₹"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"रबि"),tsc(u"सम"),tsc(u"मंगल"),tsc(u"बुद"),tsc(u"बिसथि"),tsc(u"सुखुर"),tsc(u"सुनि")},.day={tsc(u"रबिबार"),tsc(u"सोबार"),tsc(u"मंगलबार"),tsc(u"बुदबार"),tsc(u"बिसथिबार"),tsc(u"सुखुरबार"),tsc(u"सुनिबार")},.abmon={tsc(u"जानुवारी"),tsc(u"फेब्रुवारी"),tsc(u"मार्स"),tsc(u"एप्रिल"),tsc(u"मे"),tsc(u"जुन"),tsc(u"जुलाइ"),tsc(u"आगस्थ"),tsc(u"सेबथेज्ब़र"),tsc(u"अखथबर"),tsc(u"नबेज्ब़र"),tsc(u"दिसेज्ब़र")},.mon={tsc(u"जानुवारी"),tsc(u"फेब्रुवारी"),tsc(u"मार्स"),tsc(u"एफ्रिल"),tsc(u"मे"),tsc(u"जुन"),tsc(u"जुलाइ"),tsc(u"आगस्थ"),tsc(u"सेबथेज्ब़र"),tsc(u"अखथबर"),tsc(u"नबेज्ब़र"),tsc(u"दिसेज्ब़र")},.d_t_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u"%-m//%-d//%y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"फुं."),tsc(u"बेलासे.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yYह]"),.noexpr=tsc(u"^[-0nNन]"),.yesstr=tsc(u"हाँ"),.nostr=tsc(u"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"91")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u""),.name_miss=tsc(u"Miss."),.name_mr=tsc(u"Mr."),.name_mrs=tsc(u"Mrs."),.name_ms=tsc(u"Ms.")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"भारत"),.country_ab2=tsc(u"IN"),.country_ab3=tsc(u"IND"),.country_num=356,.country_car=tsc(u"IND"),.lang_name=tsc(u"बड़ो"),.lang_term=tsc(u"brx"),.lang_lib=tsc(u"brx")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.title=tsc(U"Bodo language locale for India"),.source=tsc(U"Red Hat Pune\t\t;\t\tfast_io"),.address=tsc(U"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Bodo"),.territory=tsc(U"India"),.revision=tsc(U"1.0"),.date=tsc(U"2011-10-17")},.monetary={.int_curr_symbol=tsc(U"INR "),.currency_symbol=tsc(U"₹"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"रबि"),tsc(U"सम"),tsc(U"मंगल"),tsc(U"बुद"),tsc(U"बिसथि"),tsc(U"सुखुर"),tsc(U"सुनि")},.day={tsc(U"रबिबार"),tsc(U"सोबार"),tsc(U"मंगलबार"),tsc(U"बुदबार"),tsc(U"बिसथिबार"),tsc(U"सुखुरबार"),tsc(U"सुनिबार")},.abmon={tsc(U"जानुवारी"),tsc(U"फेब्रुवारी"),tsc(U"मार्स"),tsc(U"एप्रिल"),tsc(U"मे"),tsc(U"जुन"),tsc(U"जुलाइ"),tsc(U"आगस्थ"),tsc(U"सेबथेज्ब़र"),tsc(U"अखथबर"),tsc(U"नबेज्ब़र"),tsc(U"दिसेज्ब़र")},.mon={tsc(U"जानुवारी"),tsc(U"फेब्रुवारी"),tsc(U"मार्स"),tsc(U"एफ्रिल"),tsc(U"मे"),tsc(U"जुन"),tsc(U"जुलाइ"),tsc(U"आगस्थ"),tsc(U"सेबथेज्ब़र"),tsc(U"अखथबर"),tsc(U"नबेज्ब़र"),tsc(U"दिसेज्ब़र")},.d_t_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(U"%-m//%-d//%y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"फुं."),tsc(U"बेलासे.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yYह]"),.noexpr=tsc(U"^[-0nNन]"),.yesstr=tsc(U"हाँ"),.nostr=tsc(U"नहीं")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"91")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U""),.name_miss=tsc(U"Miss."),.name_mr=tsc(U"Mr."),.name_mrs=tsc(U"Mrs."),.name_ms=tsc(U"Ms.")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"भारत"),.country_ab2=tsc(U"IN"),.country_ab3=tsc(U"IND"),.country_num=356,.country_car=tsc(U"IND"),.lang_name=tsc(U"बड़ो"),.lang_term=tsc(U"brx"),.lang_lib=tsc(U"brx")},.measurement={.measurement=1}};


}
}

#include"../main.h"