﻿#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.title=tsc("Irish locale for Ireland with Euro"),.source=tsc("Free Software Foundation, Inc.\t\t;\t\tfast_io"),.address=tsc("https://www.gnu.org/software/libc/\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc("fast_io"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Irish"),.territory=tsc("Ireland"),.revision=tsc("1.0"),.date=tsc("2000-08-21")},.monetary={.int_curr_symbol=tsc("EUR "),.currency_symbol=tsc("€"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Domh"),tsc("Luan"),tsc("Máirt"),tsc("Céad"),tsc("Déar"),tsc("Aoine"),tsc("Sath")},.day={tsc("Dé Domhnaigh"),tsc("Dé Luain"),tsc("Dé Máirt"),tsc("Dé Céadaoin"),tsc("Déardaoin"),tsc("Dé hAoine"),tsc("Dé Sathairn")},.abmon={tsc("Ean"),tsc("Feabh"),tsc("Márta"),tsc("Aib"),tsc("Beal"),tsc("Meith"),tsc("Iúil"),tsc("Lún"),tsc("MFómh"),tsc("DFómh"),tsc("Samh"),tsc("Noll")},.mon={tsc("Eanáir"),tsc("Feabhra"),tsc("Márta"),tsc("Aibreán"),tsc("Bealtaine"),tsc("Meitheamh"),tsc("Iúil"),tsc("Lúnasa"),tsc("Meán Fómhair"),tsc("Deireadh Fómhair"),tsc("Samhain"),tsc("Nollaig")},.d_t_fmt=tsc("%a %d %b %Y %T"),.d_fmt=tsc("%d.%m.%y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %d %b %Y %T %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1tTyY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("tá"),.nostr=tsc("níl")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("353")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Éire"),.country_ab2=tsc("IE"),.country_ab3=tsc("IRL"),.country_num=372,.country_car=tsc("IRL"),.lang_name=tsc("Gaeilge"),.lang_ab=tsc("ga"),.lang_term=tsc("gle"),.lang_lib=tsc("gle")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.title=tsc(L"Irish locale for Ireland with Euro"),.source=tsc(L"Free Software Foundation, Inc.\t\t;\t\tfast_io"),.address=tsc(L"https://www.gnu.org/software/libc/\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Irish"),.territory=tsc(L"Ireland"),.revision=tsc(L"1.0"),.date=tsc(L"2000-08-21")},.monetary={.int_curr_symbol=tsc(L"EUR "),.currency_symbol=tsc(L"€"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Domh"),tsc(L"Luan"),tsc(L"Máirt"),tsc(L"Céad"),tsc(L"Déar"),tsc(L"Aoine"),tsc(L"Sath")},.day={tsc(L"Dé Domhnaigh"),tsc(L"Dé Luain"),tsc(L"Dé Máirt"),tsc(L"Dé Céadaoin"),tsc(L"Déardaoin"),tsc(L"Dé hAoine"),tsc(L"Dé Sathairn")},.abmon={tsc(L"Ean"),tsc(L"Feabh"),tsc(L"Márta"),tsc(L"Aib"),tsc(L"Beal"),tsc(L"Meith"),tsc(L"Iúil"),tsc(L"Lún"),tsc(L"MFómh"),tsc(L"DFómh"),tsc(L"Samh"),tsc(L"Noll")},.mon={tsc(L"Eanáir"),tsc(L"Feabhra"),tsc(L"Márta"),tsc(L"Aibreán"),tsc(L"Bealtaine"),tsc(L"Meitheamh"),tsc(L"Iúil"),tsc(L"Lúnasa"),tsc(L"Meán Fómhair"),tsc(L"Deireadh Fómhair"),tsc(L"Samhain"),tsc(L"Nollaig")},.d_t_fmt=tsc(L"%a %d %b %Y %T"),.d_fmt=tsc(L"%d.%m.%y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %d %b %Y %T %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1tTyY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"tá"),.nostr=tsc(L"níl")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"353")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Éire"),.country_ab2=tsc(L"IE"),.country_ab3=tsc(L"IRL"),.country_num=372,.country_car=tsc(L"IRL"),.lang_name=tsc(L"Gaeilge"),.lang_ab=tsc(L"ga"),.lang_term=tsc(L"gle"),.lang_lib=tsc(L"gle")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.title=tsc(u8"Irish locale for Ireland with Euro"),.source=tsc(u8"Free Software Foundation, Inc.\t\t;\t\tfast_io"),.address=tsc(u8"https://www.gnu.org/software/libc/\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Irish"),.territory=tsc(u8"Ireland"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000-08-21")},.monetary={.int_curr_symbol=tsc(u8"EUR "),.currency_symbol=tsc(u8"€"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Domh"),tsc(u8"Luan"),tsc(u8"Máirt"),tsc(u8"Céad"),tsc(u8"Déar"),tsc(u8"Aoine"),tsc(u8"Sath")},.day={tsc(u8"Dé Domhnaigh"),tsc(u8"Dé Luain"),tsc(u8"Dé Máirt"),tsc(u8"Dé Céadaoin"),tsc(u8"Déardaoin"),tsc(u8"Dé hAoine"),tsc(u8"Dé Sathairn")},.abmon={tsc(u8"Ean"),tsc(u8"Feabh"),tsc(u8"Márta"),tsc(u8"Aib"),tsc(u8"Beal"),tsc(u8"Meith"),tsc(u8"Iúil"),tsc(u8"Lún"),tsc(u8"MFómh"),tsc(u8"DFómh"),tsc(u8"Samh"),tsc(u8"Noll")},.mon={tsc(u8"Eanáir"),tsc(u8"Feabhra"),tsc(u8"Márta"),tsc(u8"Aibreán"),tsc(u8"Bealtaine"),tsc(u8"Meitheamh"),tsc(u8"Iúil"),tsc(u8"Lúnasa"),tsc(u8"Meán Fómhair"),tsc(u8"Deireadh Fómhair"),tsc(u8"Samhain"),tsc(u8"Nollaig")},.d_t_fmt=tsc(u8"%a %d %b %Y %T"),.d_fmt=tsc(u8"%d.%m.%y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %d %b %Y %T %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1tTyY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"tá"),.nostr=tsc(u8"níl")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"353")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Éire"),.country_ab2=tsc(u8"IE"),.country_ab3=tsc(u8"IRL"),.country_num=372,.country_car=tsc(u8"IRL"),.lang_name=tsc(u8"Gaeilge"),.lang_ab=tsc(u8"ga"),.lang_term=tsc(u8"gle"),.lang_lib=tsc(u8"gle")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.title=tsc(u"Irish locale for Ireland with Euro"),.source=tsc(u"Free Software Foundation, Inc.\t\t;\t\tfast_io"),.address=tsc(u"https://www.gnu.org/software/libc/\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Irish"),.territory=tsc(u"Ireland"),.revision=tsc(u"1.0"),.date=tsc(u"2000-08-21")},.monetary={.int_curr_symbol=tsc(u"EUR "),.currency_symbol=tsc(u"€"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Domh"),tsc(u"Luan"),tsc(u"Máirt"),tsc(u"Céad"),tsc(u"Déar"),tsc(u"Aoine"),tsc(u"Sath")},.day={tsc(u"Dé Domhnaigh"),tsc(u"Dé Luain"),tsc(u"Dé Máirt"),tsc(u"Dé Céadaoin"),tsc(u"Déardaoin"),tsc(u"Dé hAoine"),tsc(u"Dé Sathairn")},.abmon={tsc(u"Ean"),tsc(u"Feabh"),tsc(u"Márta"),tsc(u"Aib"),tsc(u"Beal"),tsc(u"Meith"),tsc(u"Iúil"),tsc(u"Lún"),tsc(u"MFómh"),tsc(u"DFómh"),tsc(u"Samh"),tsc(u"Noll")},.mon={tsc(u"Eanáir"),tsc(u"Feabhra"),tsc(u"Márta"),tsc(u"Aibreán"),tsc(u"Bealtaine"),tsc(u"Meitheamh"),tsc(u"Iúil"),tsc(u"Lúnasa"),tsc(u"Meán Fómhair"),tsc(u"Deireadh Fómhair"),tsc(u"Samhain"),tsc(u"Nollaig")},.d_t_fmt=tsc(u"%a %d %b %Y %T"),.d_fmt=tsc(u"%d.%m.%y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %d %b %Y %T %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1tTyY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"tá"),.nostr=tsc(u"níl")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"353")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Éire"),.country_ab2=tsc(u"IE"),.country_ab3=tsc(u"IRL"),.country_num=372,.country_car=tsc(u"IRL"),.lang_name=tsc(u"Gaeilge"),.lang_ab=tsc(u"ga"),.lang_term=tsc(u"gle"),.lang_lib=tsc(u"gle")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.title=tsc(U"Irish locale for Ireland with Euro"),.source=tsc(U"Free Software Foundation, Inc.\t\t;\t\tfast_io"),.address=tsc(U"https://www.gnu.org/software/libc/\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Irish"),.territory=tsc(U"Ireland"),.revision=tsc(U"1.0"),.date=tsc(U"2000-08-21")},.monetary={.int_curr_symbol=tsc(U"EUR "),.currency_symbol=tsc(U"€"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Domh"),tsc(U"Luan"),tsc(U"Máirt"),tsc(U"Céad"),tsc(U"Déar"),tsc(U"Aoine"),tsc(U"Sath")},.day={tsc(U"Dé Domhnaigh"),tsc(U"Dé Luain"),tsc(U"Dé Máirt"),tsc(U"Dé Céadaoin"),tsc(U"Déardaoin"),tsc(U"Dé hAoine"),tsc(U"Dé Sathairn")},.abmon={tsc(U"Ean"),tsc(U"Feabh"),tsc(U"Márta"),tsc(U"Aib"),tsc(U"Beal"),tsc(U"Meith"),tsc(U"Iúil"),tsc(U"Lún"),tsc(U"MFómh"),tsc(U"DFómh"),tsc(U"Samh"),tsc(U"Noll")},.mon={tsc(U"Eanáir"),tsc(U"Feabhra"),tsc(U"Márta"),tsc(U"Aibreán"),tsc(U"Bealtaine"),tsc(U"Meitheamh"),tsc(U"Iúil"),tsc(U"Lúnasa"),tsc(U"Meán Fómhair"),tsc(U"Deireadh Fómhair"),tsc(U"Samhain"),tsc(U"Nollaig")},.d_t_fmt=tsc(U"%a %d %b %Y %T"),.d_fmt=tsc(U"%d.%m.%y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %d %b %Y %T %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1tTyY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"tá"),.nostr=tsc(U"níl")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"353")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Éire"),.country_ab2=tsc(U"IE"),.country_ab3=tsc(U"IRL"),.country_num=372,.country_car=tsc(U"IRL"),.lang_name=tsc(U"Gaeilge"),.lang_ab=tsc(U"ga"),.lang_term=tsc(U"gle"),.lang_lib=tsc(U"gle")},.measurement={.measurement=1}};


}
}

#include"../main.h"