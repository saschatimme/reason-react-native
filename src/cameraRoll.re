type config;

type node = {
  .
  "_type": string,
  "group_name": string,
  "image": {
    .
    "filename": string,
    "playableDuration": int,
    "uri": string,
    "height": int,
    "width": int,
    "isStored": bool
  },
  "location": {
    .
    "altitude": float,
    "heading": float,
    "latitude": float,
    "longitude": float,
    "speed": float
  },
  "timestamp": float
};

type result = {
  .
  "edges": array(node),
  "page_info": {
    .
    "has_next_page": bool,
    "start_cursor": bool,
    "end_cursor": bool
  }
};

type fileType =
  | Video
  | Photo;

type groupType =
  | All
  | Album
  | Event
  | Faces
  | Library
  | PhotoStream
  | SavedPhotos;

type assetType =
  | All
  | Videos
  | Photos;

let mapFileType = fileType =>
  switch fileType {
  | Photo => "photo"
  | Video => "video"
  };

let mapGroupType = (groupType: groupType) =>
  switch groupType {
  | All => "All"
  | Album => "Album"
  | Event => "Event"
  | Faces => "Faces"
  | Library => "Library"
  | PhotoStream => "PhotoStream"
  | SavedPhotos => "SavedPhotos"
  };

let mapAssetType = (assetType: assetType) =>
  switch assetType {
  | All => "All"
  | Videos => "Videos"
  | Photos => "Photos"
  };

[@bs.obj]
external makeConfig :
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: string,
    ~groupName: string=?,
    ~assetType: string,
    ~mimeTypes: string=?
  ) =>
  config =
  "";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external _saveToCameraRoll :
  (string, Js.Undefined.t(string)) => Js.Promise.t(string) =
  "saveToCameraRoll";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external _getPhotos : config => Js.Promise.t(result) = "getPhotos";

let saveToCameraRoll = (~uri, ~type_=?, ()) => {
  let fileType = Js.Undefined.from_opt(UtilsRN.option_map(mapFileType, type_));
  _saveToCameraRoll(uri, fileType);
};

let getPhotos =
    (
      ~first,
      ~after=?,
      ~groupTypes=SavedPhotos,
      ~groupName=?,
      ~assetType=Photos,
      ~mimeTypes=?,
      ()
    ) => {
  let groupTypes = mapGroupType(groupTypes);
  let assetType = mapAssetType(assetType);
  let config =
    makeConfig(
      ~first,
      ~after?,
      ~groupTypes,
      ~groupName?,
      ~assetType,
      ~mimeTypes?
    );
  _getPhotos(config);
};