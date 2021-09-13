[@bs.module "../../../public/strings/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ru.json"]
external ru: array(Translation.t) = "default";
[@bs.module "../../../public/strings/zh.json"]
external zh: array(Translation.t) = "default";


type t =
  | English
  | Russian
  | SimplifiedChinese;

let allLanguages = [|English, Russian, SimplifiedChinese|];

let toISOCode = t => {
  switch (t) {
  | English => "en"
  | Russian => "ru"
  | SimplifiedChinese => "zh"
  };
};

let isoCodeToLocale = t => {
  switch (t) {
  | "zh" => SimplifiedChinese
  | "ru" => Russian
  | "en"
  | _ => English
  };
};

let translations = t => {
  switch (t) {
  | English => en
  | Russian => ru
  | SimplifiedChinese => zh
  };
};

let toStringLanguage = t => {
  switch (t) {
  | English => "English"
  | Russian => "Russian"
  | SimplifiedChinese => "Chinese"
  };
};

let currentLangFromUrl = url =>
  Js.String.split("/", url)->Belt.Array.sliceToEnd(1)[0]->isoCodeToLocale;
