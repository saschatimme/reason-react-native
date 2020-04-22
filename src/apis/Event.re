// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type syntheticEvent('a) = {
  .
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
};

type responderSyntheticEvent('a) = {
  .
  // synthethicEvent keys
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
  // responderSyntheticEvent additional key
  "touchHistory": {
    .
    "indexOfSingleActiveTouch": float,
    "mostRecentTimeStamp": float,
    "numberActiveTouches": float,
    "touchBank":
      array({
        .
        "touchActive": bool,
        "startPageX": float,
        "startPageY": float,
        "startTimeStamp": float,
        "currentPageX": float,
        "currentPageY": float,
        "currentTimeStamp": float,
        "previousPageX": float,
        "previousPageY": float,
        "previousTimeStamp": float,
      }),
  },
};

module TextLayout = {
  module Line = {
    type t = {
      x: float,
      y: float,
      width: float,
      height: float,
      ascender: float, // verify
      capHeight: float, // verify
      descender: float, // verify
      text: string,
      xHeight: float // verify
    };
  };
  type t = {lines: array(Line.t)};
};

module LayoutEvent = {
  module Layout = {
    type t = {
      x: float,
      y: float,
      width: float,
      height: float,
    };
  };
  type t = {layout: Layout.t};
};

type layout = LayoutEvent.t;
type layoutEvent = syntheticEvent(layout);

type textLayout = TextLayout.Line.t;
type textLayouts = TextLayout.t;
type textLayoutEvent = syntheticEvent(textLayouts);

module PressEvent = {
  type t = {
    changedTouches: array(t),
    force: float,
    identifier: int,
    locationX: float,
    locationY: float,
    pageX: float,
    pageY: float,
    target: Js.Nullable.t(float),
    timestamp: float,
    touches: array(t),
  };
};
type pressEventPayload = PressEvent.t;
type pressEvent = responderSyntheticEvent(pressEventPayload);

module Dimensions = {
  type t = {
    height: float,
    width: float,
  };
};

type dimensions = Dimensions.t;

module ScrollEvent = {
  module ContentOffset = {
    type t = {
      x: float,
      y: float,
    };
  };

  module ContentInset = {
    type t = {
      bottom: float,
      left: float,
      right: float,
      top: float,
    };
  };

  type t = {
    contentInset: ContentInset.t,
    contentOffset: ContentOffset.t,
    contentSize: dimensions,
    layoutMeasurement: dimensions,
  };
};

type contentOffset = ScrollEvent.ContentOffset.t;
type contentInset = ScrollEvent.ContentInset.t;
type scrollEventPayload = ScrollEvent.t;
type scrollEvent = syntheticEvent(scrollEventPayload);

module SwitchChangePayload = {
  type t = {value: bool};
};

type switchChangePayload = SwitchChangePayload.t;
type switchChangeEvent = syntheticEvent(switchChangePayload);

module TargetEvent = {
  type t = {target: int};
};

type targetPayload = TargetEvent.t;
type targetEvent = syntheticEvent(targetPayload);
