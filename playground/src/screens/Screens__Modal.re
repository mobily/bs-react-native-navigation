open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            flex(1.),
            backgroundColor("#46D26B"),
            alignItems(Center),
            justifyContent(Center),
          ]),
        "text":
          style([
            color("#fff"),
            fontSize(Float(32.)),
            marginBottom(Pt(20.)),
            fontWeight(`Bold),
          ]),
      }
    ),
  );

let component = statelessComponent("Modal");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("Modal!")) </Text>
      <TouchableOpacity onPress=(_event => Navigation.dismissModal())>
        <Text> (stringToElement("Dismiss Modal")) </Text>
      </TouchableOpacity>
      <TouchableOpacity
        onPress=(_event => Navigator.dismissModal(~navigator, ()))>
        <Text> (stringToElement("Dismiss Modal (with navigator)")) </Text>
      </TouchableOpacity>
    </View>,
};

let default = Utils.nativeScreen(~component, ~make);

Utils.setNavigatorStyle(
  ~nativeScreen=default,
  ~navigatorStyle=Navigator.Style.(create([navBarHidden(true)])),
);
